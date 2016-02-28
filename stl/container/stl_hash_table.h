
template <class Value>
struct __hashtable_node {
    __hashtable_node* next;
    Value val;
};

template <class Value, class Key, class HashFcn, class ExtractKey, class EqualKey, class Alloc> 
struct __hashtable_iterator {
    typedef hashtable<Value, Key, HashFcn, ExtractKey, EqualKey, Alloc>  hashtable;   
    typedef __hashtable_iterator<Value, Key, HashFcn, ExtractKey, EqualKey, Alloc> iterator;

    typedef __hashtable_const_iterator<Value, Key, HashFcn, ExtractKey, EqualKey, Alloc> const_iterator;
    typedef __hashtable_node<Value> node;

    typedef forward_iterator_tag iterator_category;
    typedef Value value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef Value& reference;
    typedef Value* pointer;

    node* cur;
    hashtable* ht;

    __hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab) {}
    __hashtable_iterator() {}
    reference operator*() const {return cur->val;}
    pointer operator->() const {return &(operator*());}
    iterator& operator++();
    iterator operator++(int);
    bool operator==(const iterator& it) {return cur == it.cur;}
    bool operator!=(const iterator& it) {return cur != it.cur;}
} /* optional variable list */;


template <class V, class K, class HF, class ExK, class EqK, class A>
__hashtable_iterator<V, K, HF, ExK, EqK, A>& 
__hashtable_iterator<V, K, HF, ExK, EqK, A>::operator++(){
    const node* old = cur;
    cur = cur->next;
    if(!cur){
        size_type bucket = ht->bkt_num(old->val);
        while(!cur && ++bucket < ht->bucket.size())
            cur = ht->buckets[bucket];
    }
    return *this;
}

template <class V, class K, class HF, class ExK, class EqK, class A>
__hashtable_iterator<V, K, HF, ExK, EqK, A>& 
__hashtable_iterator<V, K, HF, ExK, EqK, A>::operator++(int){
    iterator tmp = *this;
    ++this;
    return tmp;
}


template <class Value, class Key, class HashFcn, class ExtractKey, class EqualKey, class Alloc> 
class hashtable{
    public:
        typedef HashFcn hasher;
        typedef EqualKey key_equal;
        typedef size_t size_type;

    private:
        hasher hash;
        key_equal equals;
        ExtractKey get_key;

        typedef __hashtable_node<Value> node;
        typedef simple_alloc<node, Alloc> node_allocator;

       vector<node*, Alloc> buckets;
       size_type num_elements;

    public:
       size_type bucket_count() const {return buckets.size();}
       static const int __stl_num_primes = 28;
       static const unsigned long __stl_num_prime_list[__stl_num_prime_list] = {
            53, 97, // 等28个质数
       };

       inline unsigned long __stl_next_prime(unsigned long n){
            const unsigned long* first = __stl_num_prime_list;
            const unsigned long* last = __stl_num_prime_list + __stl_num_primes;
            const unsigned long* pos = lower_bound(first, last, n);
            return pos == last ? *(last-1) : *pos;
       }

       size_type max_bucket_count() const
       {
           return __stl_num_prime_list[__stl_next_prime-1];
       }

        node* new_node(const value_type& obj){
            node* n = node_allocator::allocate();
            n->next = 0;
            __STL_TRY{
                construct(&n->val, obj);
                return n;
            }

            __STL_UNWIND(node_allocator::deallocate(n));
        }

        void delete_node(node* p){
            destroy(&p->val);
            node_allocator::deallocate(n);
        }

        hashtable(size_type n, const HashFcn& hf, const EqualKey& eql)
            :hash(hf), equals(eql), get_key(ExtractKey()), num_elements(0)
        {
            inititalize_buckets(n);
        }

        void inititalize_buckets(size_type n){
            const size_type n_buckets = next_size(n);
            buckets.reverse(n_buckets);
            buckets.insert(buckets.end(), n_buckets, (node*)0);
            num_elements = 0;
        }

        size_type next_size(size_type n)
        {
            return __stl_next_prime(n);
        }

        pair<iterator, bool> insert_unique(const value_type& obj){
            resize(num_elements+1);
            return insert_unique(obj);
        }

        void resize(size_type num_elements_hint){
            const size_type old_n = buckets.size();
            if(num_elements_hint > old_n){
                vector<node*, A> tmp(n, (node*)0);
                __STL_TRY{
                  for(size_type bucket = 0; bucket < old_n; ++bucket){
                    node* first = buckets[bucket];
                    while (first) {
                        size_type new_bucket = bkt_num(first->val, n);
                        buckets[bucket] = first->next;
                        first->next = tmp[new_bucket];
                        tmp[new_bucket] = first;
                        first = buckets[bucket];
                    }
                  }
                  buckets.swap(tmp);
                }
            }
        }

        pair<iterator, bool> insert_unique_noresize(const value_type& obj)
        {
            const size_type n = bkt_num(obj);
            node* first = buckets[n];
            for(node* cur = first; ; cur = cur->next){
                if(equals(get_key(cur->value), get_key(obj)))
                    return pair<iterator, bool> (iterator(cur, this), false);

            }
            node* tmp = new_node(obj);
            tmp->next = first;
            buckets[n] = tmp;
            ++num_elements;
            return pair<iterator, bool>(iterator(tmp, this), true);
        }
        iterator insert_equal(const value_type& obj)
        {
            resize(num_elements+1);
            return insert_equal_noresize(obj);
        }

        iterator insert_equal_noresize(const value_type& obj)
        {
            const size_type n= bkt_num(obj);
            node* first = buckets[n];
            for(node * cur = first; cur; cur = cur->next){
                if(equals(get_key(cur->val), get_key(obj))){
                    node* tmp = new_node(obj);
                    tmp->next = cur->next;
                    cur->next = tmp;
                    ++num_elements;
                    return iterator(tmp, this);
                }
            }
            node* tmp = new_node(obj);
            tmp->next = first;
            buckets[n] = tmp;
            ++num_elements;
            return iterator(tmp, this);
        }

        size_type bkt_num(const value_type& obj, size_t n) const{
            return bkt_num_key(get_key(obj), n);
        }
        size_type bkt_num(const value_type& obj) const{
            return bkt_num_key(get_key(obj));
        }
        size_type bkt_num_key(const value_type& key) const {
            return bkt_num_key(key, buckets.size());
        }
        size_type bkt_num_key(const value_type& key, size_t n) const {
            return hash(key)% n;
        }
        void clear()
        {
            for(size_type i = 0; i < buckets.size(); ++i){
                node* cur = buckets[i];
                while(cur != 0){
                    node* next = cur->next;
                    delete_node(cur);
                    cur = next;
                }
                buckets[i] = 0;
            }
            num_elements = 0;

        }

        void copy_frome(const hashtable& ht){
            buckets.clear();
            buckets.reserve(ht.buckets.size());
            buckets.insert(buckets.end(), ht.buckets.size(), (node*) 0);
            __STL_TRY{
                for(size_type i = 0; i < ht.buckets.size(); ++i){
                    node* copy = new_node(cur->val);
                    buckets[i] = copy;
                    for(node* next = cur->next; next; cur = next, next = cur->next){
                        copy->next = new_node(next->val);
                        copy = copy->next;
                    }
                }
            num_elements = st.num_elements;
            }
            __STL_UNWIND(clear());
        }
        iterator find(const key_type& key){
            const size_type n = bkt_num_key(key);
            node* first;
            for(first = buckets[n]; first && !equals(get_key(first->val), key); first = first->next)
            {}
            return iterator(first, this);
        }

        size_type count(const key_type& key) const{
            const size_type n = bkt_num_key(key);
            size_type result = 0;
            for(const node* cur = buckets[n]; cur; cur = cur->next)
                if(equals(get_key(cur->val), key))
                    ++result;
            return result;
        }
};
