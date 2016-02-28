#include <iostream>
using namespace std;

template <class Iterator>
struct itertor_traits{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

template <class T>
struct iterator_traits<T*>{
    typedef random_access_itertor iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

};


template <class T>
struct iterator_traits<const T*>{
    typedef random_access_itertor iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;

};

template<class Category, class Value,
    class Distance = ptrdiff_t,
    class Pointer = Value*,
    class Reference = Value&>
struct Iterator{
    typedef Category iterator_category;
    typedef Value value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

template <class Node, class Reference class Pointer>
struct node_wrap_base:
    public itertor<forward_iterator_tag, Node,
    ptrdiff_t, Pointer, Reference>{
    typedef node_wrap_base<Node, Node&, Node*> iterator;
    typedef node_wrap_base<Node, const Node&, const Node*> const_iterator;
    Pointer ptr;
    node_wrap_base(Pointer p = 0):ptr(p){}
    node_wrap_base(const iterator& x):ptr(x.ptr){}

    Reference operator*()const {return *ptr;}
    Pointer operator->()const{return ptr};

    void incr(){ ptr = ptr->next;}

    bool operator==(const node_wrap_base& x) const{return ptr == x.ptr;}
    bool operator!=(const node_wrap_base& x) const{return ptr != x.ptr;}
};

template <class Node>
struct node_wrap: public node_wrap_base<Node, Node&, Node*>
{
    typedef node_wrap_base<Node, Node&, Node*> Base;
    node_wrap(Node* p = 0): Base(p) {}
    node_wrap(const node_wrap<Node>& x): Base(x){}
    node_wrap& operator++(){
        incr();
        return *this;
    }

    node_wrap operator++(int){
        node_wrap tmp = *this;
        incr();
        return *this;
    }
};


