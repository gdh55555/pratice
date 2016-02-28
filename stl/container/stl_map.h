
#include "stl_rb_tree.h"

template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair() first(T1()), second(T2()) {}
    pair(const T1& a, const T2& b) : first(a), second(b) {}
} /* optional variable list */; 

template <class Key, class T, class Compare = less<Key>, class Alloc = alloc>    
class map {
public:
    typedef Key key_type;
    typedef T data_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;

    class value_compare
        : public binary_function<value_type, value_type, bool>{
            friend class map<Key, T, Compare, Alloc>;
            protected:
                Compare comp;
                value_compare(Compare c) :comp(c) {}

            public:
                bool operator()(const value_type&x , const value_type& y) const{
                    return comp(x.first, y.first);
                }
        };

private:
    typedef rb_tree<key_type, value_type, selectlst<value_type>, key_compare, Alloc> rep_type;

    map() : t(Compare()) {}
    explicit map(const Compare& comp) :t(comp){}
    T& operator[](const key_value& k){
        return (*((insert(value_type(k, T()))).first)).second;
    }
};
