
 typedef bool __rb_tree_color_type;

 const __rb_tree_color_type __rb_tree_red = false;
 const __rb_tree_color_type __rb_tree_black = true;

 struct __rb_tree_node_base {
     typedef __rb_tree_color_type color_type;
     typedef __rb_tree_node_base* base_ptr ;

     color_type color;
     base_ptr parent;
     base_ptr left;
     base_ptr right;
 } /* optional variable list */;

static base_ptr minimum(base_ptr x)
{
    while (x->left != 0){
        x = x->left;
    }
    return x;
}

static base_ptr maximun(base_ptr x)
{
    while (x->right != 0) {
        x = x->right;
    }
    return x;
}

template <class value>
struct __rb_tree_node : public __rb_tree_node_base {
    typedef __rb_tree_node_base<Value>* link_type;

    Value value_field;
};

struct __rb_tree_base_iterator {
    typedef __rb_tree_node_base::base_ptr base_ptr;
    typedef bidirectional_iterator_tag iterator_category;
    
    typedef ptrdiff_t difference_type;
    base_ptr node; //用来与容器之间产生一个连接关系

    void increment()
    {
        if (node->right != 0) {     //如果右节点存在，则寻找右节点的最左节点
            node = node->right;     //即为最小节点
            while (node->left != 0) {
                node = node->left;
            }
        }else {                     //如果右节点不存在， 则找其父亲节点
            base_ptr y = node->parent;  //过过现行节点本身就是一个右节点，则一直向上寻找
            while (node == y->right) {
                node = y;
                y = y->parent;
            }
            if (node->right != y) {     //如果此时的右子节点不等于此时的父节点
                node = y;               //则node为y
            }
        }
    }

    void decrement()
    {
        if (node->color == __rb_tree_red && 
                node->parent->parent == node) {  //此处不是太明白
            node = node->right;
        }
        else if (node->left != 0) {
            base_ptr y = node->left;
            while (y->right != 0) {
                y = y->right;  
            }
            node = y;
        }   
    }else {
        base_ptr y = node->parent;
        while (node == y->left) {
            node = y;
            y = y->parent;
        }
        node = y;
    }

};

template <class Value, class Ref, class Ptr>
struct __rb_tree_iterator : public __rb_tree_base_iterator {
    typedef Value value_type;
    typedef Ref referenct;
    typedef Ptr pointer;
    typedef __rb_tree_iterator<Value, Value&, value*> iterator;
    typedef __rb_tree_iterator<Value, const Value&, const Value*> const_iterator;
    typedef __rb_tree_iterator<Value, Ref, Ptr> self;
    typedef __rb_tree_node<Value>* link_type;

    __rb_tree_iterator() {}
    __rb_tree_iterator(link_type x) {node = x;}
    __rb_tree_iterator(const iterator& it) {node = it.node;}

    referenct operator() const
    {
        return link_type(node)->value_field;
    }

#ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator->() const
    {
        return &(operator*());
    }
#endif
    self& operator++() {increment(); return *this;}
    self operator++(int)   
    {
        self tmp = *this;
        increment();
        return tmp;
    }
    
    self& operator--() {decrement(); return *this;}
    self operator--(int)
    {
        self tmp = *this;
        decrement();
        return tmp;
    }
} ;

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc = alloc>
class rb_tree {
    protected:
        typedef void* void_pointer;
        typedef __rb_tree_node_base* base_ptr;
        typedef __rb_tree_node<Value> rb_tree_node;
        typedef simple_alloc<rb_tree_node, Alloc> rb_tree_node_allocator;
        typedef __rb_tree_color_type color_type;

    public:
        typedef Key key_type;  
        typedef Value value_type;
        typedef value_type* pointer;
        typedef const value_type const_pointer;
        typedef value_type& referenct;
        typedef const value_type const_reference;
        typedef rb_tree_node* link_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

    protected:
        link_type get_node() {return rb_tree_node_allocator::allocate();}
        void put_node(link_type p)
        {
            rb_tree_node_allocator::deallocate(p); 
        }
        link_type create_node(const value_type& x)
        {
            link_type tmp = get_node();
            __STL_TRY{
                construct(&tmp->value_type, x);
            }

            __STL_UNBIND(put_node(tmp));
            return tmp;
        }
        link_type clone_node(link_type x)
        {
            link_type tmp = create_node(x->value_field);
            tmp->color = x->color;
            tmp->left = 0;
            tmp->right = 0;
            return tmp;
        }
        void destroy_node(link_type p)
        {
            destroy(&p->value_field);
            put_node(p);
        }

    protected:
        size_type node_count;
        link_type header;
        Compare key_compare;
        //一下三个函数用来方便获得header的成员
        link_type& root() cosnt {return (link_type&) header->parent;}
        link_type& leftmost() const { return (link_type&) header->left;}
        link_type& rightmost() cosnt { return (link_type&) header->right;}

        //以下六个函数用来方便获得节点x的成员
        static link_type& left(link_type x)
        {
            return (link_type&)(x->left); 
        }

        static link_type& right(link_type x)
        {
            return (link_type&)(x->right); 
        }
        static link_type& parent(link_type x)
        {
            return (link_type&)(x->parent); 
        }
        static referenct value(link_type x)
        {
            return (x->value_field); 
        }
        static const Key&& key(link_type x)
        {
            return KeyOfValue()(value(x));
        }
        static color_type& color(link_type x)
        {
            return (color_type&)(x->color);
        }
        //以下六个函数用来方便获得节点x的成员
        static link_type& left(base_ptr x)
        {
            return (link_type&)(x->left); 
        }

        static link_type& right(base_ptr x)
        {
            return (link_type&)(x->right); 
        }
        static link_type& parent(base_ptr x)
        {
            return (link_type&)(x->parent); 
        }
        static referenct value(base_ptr x)
        {
            return (((link_type)x)->value_field); 
        }
        static const Key&& key(link_type x)
        {
            return KeyOfValue()(value(x));
        }
        static color_type& color(base_ptr x)
        {
            return (color_type&)(((link_type)x)->color);
        }
        
        //求极大值极小值，node class 有实现此功能
        static link_type minimum(link_type x)
        {
            return (link_type) __rb_tree_node_base::minimum(x);
        }
        static link_type maximun(link_type x)
        {
            return (link_type) __rb_tree_node_base::maximun(x); 
        }
        
    public:
        typedef __rb_tree_base_iterator<value_type, referenct, pointer> iterator;   

    private:
        iterator __insert(base_ptr x, base_ptr y, const value_type& v);
        link_type __copy(link_type x, link_type p);
        void __erase(link_type x);
        void init(){
            header = get_node();
            color(header) == __rb_tree_red;

            root() = 0;
            leftmost() = header;
            rightmost() = header;

        }

    public:
        rb_tree(const Compare& comp = Compare()):
            node_count(0), key_compare(comp) {init();}

        ~rb_tree(){
            clear();
            put_node(header);
        }

        rb_tree<Key, Value, KeyOfValue, Compare, Alloc>& operator(cosnt rb_tree<Key, Value, KeyOfValue, Compare, Alloc>& x);

    public:
        Compare key_comp() const {return key_compare;}
        iterator begin() {return leftmost;}
        iterator end() {return header;}
        bool empty const {return node_count == 0;}
        size_type size() const {return node_count;}
        size_type max_size() const { return size_type(-1);}

    public:
        pair<iterator, bool> insert_unique(const value_type& x);
        iterator insert_equal(const value_type& x);
};

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc>
typename rb_tree<Key, Value, KeyOfValue, Compare, Alloc>:: iterator
rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::insert_equal(const Value& v){
    link_type y = header;
    link_type x = root();
    while(x != 0){
        y = x;
        x = key_compare(KeyOfValue()(v), key(x)) ? left(x) : right(x);
    }
    return __insert(x, y, v);

}
template <class Key, class Value, class KeyOfValue, class Compare, class Alloc>
pair<rb_tree<Key, Value, KeyOfValue, Compare, Alloc>:: iterator, bool>
rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::insert_unique(const Value& v){
    link_type y = header;
    link_type x = root();
    bool comp = true;
    while(x != 0){
        y = x;
        comp = key_compare(KeyOfValue()(v), key(x));
        x = comp ? left(x): right(x);
    }
    iterator j = iterator(y);
    if(comp){
        if (j == begin()) {
            return pair<iterator, bool>(__insert(x, y, v), true);   
        }
        else {
            --j;
        }
    }
    if(key_compare(key(j.node), KeyOfValue()(v)))
        return pair<iterator, bool>(__insert(x, y, v), true);
    return pair<iterator, bool>(j, false);  //与树的中值相等
}
template <class Key, class Value, class KeyOfValue, class Compare, class Alloc>
typename rb_tree<Key, Value, KeyOfValue, Compare, Alloc>:: iterator
rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::__insert(base_ptr x_, base_ptr y_, const Value& v){
    link_type x = (link_type)x_;
    link_type y = (link_type)y_;
    link_type z;
    if(y == header() || x != 0 || key_compare(KeyOfValue()(v), key(y))){
        z = create_node(v);
        left(y) = z;
        if (y == header) {
            root() = z;
            rightmost() = z;
        }
        else if (y == leftmost()) {
            leftmost() = z;
        }
    }
    else {
        z = create_node(v);
        right(y) = z;
        if(y == rightmost())
            rightmost() = z;
    }
    parent(z) = y;
    left(z) = 0;
    right(z) = 0;

    __rb_tree_rebalance(z, header->parent);
    ++node_count;
    return iterator(z);
}

inline void 
__rb_tree_rebalance(__rb_tree_node_base* x, __rb_tree_node_base*& root){
    x->color = __rb_tree_red;
    while (x != root && x->parent->color == __rb_tree_red) {
        if(x->parent == x->parent->parent->left){
            __rb_tree_node_base* y = x->parent->parent->right;
            if(y && y->color == __rb_tree_red){
                x->parent->color = __rb_tree_black;
                y->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                x = x->parent->parent;
            }
            else {
                if(x == x->parent->right){
                    x = x->parent;
                    __rb_tree_rorate_left(x, root);
                }
                x->parent->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                __rb_tree_rorate_right(x->parent->parent, root);
            }
        }
        else{
            __rb_tree_node_base* y = x->parent->parent->right;
            if(y && y->color == __rb_tree_red){
                x->parent->color = __rb_tree_black;
                y->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                x = x->parent->parent;
            }
            else {
                if(x == x->parent->right){
                    x = x->parent;
                    __rb_tree_rorate_right(x, root);
                }
                x->parent->color = __rb_tree_black;
                x->parent->parent = __rb_tree_red;
                __rb_tree_rorate_left(x->parent->parent, color);
            }
        }

    }
    root->color = __rb_tree_black;
}

inline void __rb_tree_rorate_left(__rb_tree_node_base* x, __rb_tree_node_base*& root){
    __rb_tree_node_base* y = x->right;
    if(y->left != 0)
        y->left->parent = x;
    y->parent = x->parent;
    if(x == root)
        root = y;
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

inline void __rb_tree_rorate_right(__rb_tree_node_base* x, __rb_tree_node_base*& root){
    __rb_tree_node_base* y = x->left;
    if(y->right != 0)
        y->right->parent = x;
    y->parent = x->parent;
    if(x == root)
        root = y;
    else if (x == x->parent->right {
        x->parent->right = y;
    }
    else
        x->parent->left = y;
    y->right = x;
    x->>parent = x;
}

template <class Key, class Value, class KeyOfValue, class Compare, class Alloc>
typename rb_tree<Key, Value, KeyOfValue, Compare, Alloc>:: iterator
rb_tree<Key, Value, KeyOfValue, Compare, Alloc>::find(const Value& v){
    link_type y = header;
    link_type x= root();
    while(x != 0)
    {
        if(!key_compare(key(x), v))
            y = x, x = left(x);
        else
            x = right(x);
    }
    iterator j = iterator(y);
    return (j == end() || key_compare(kv, key(j.node))) ? end() : j;
}
