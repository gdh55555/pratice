
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag :public input_iterator_tag {};
struct bidirectional_iterator_tag :public  forward_iterator_tag {};
struct randrom_access_iterator_tag :public bidirectional_iterator_tag {};


template <class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct iterator{
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance different_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

template <class Iterator>
struct iterator_traits{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::different_type different_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

template <class T>
struct iterator_traits<T*>{
    typedef randrom_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t different_type;
    typedef T* pointer;
    typedef T& reference;
};

template <class T>
struct iterator_traits<const T*>{
    typedef randrom_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t different_type;
    typedef const T* pointer;
    typedef const T& reference;
};


//这个函数可以很好解决迭代器的类型问题

template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&){
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}

template <class Iterator>
inline typename iterator_traits<Iterator>::different_type*
distance_type(const Iterator&){
    return static_cast<typename iterator_traits<Iterator>::different_type*>(0);
}

template <class Iterator>
inline typename iterator_traits<Iterator>::value_type*
distance_type(const Iterator&){
    return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}

//distance func
template <class InputIterator>
inline iterator_traits<InputIterator>::different_type
__distance(InputIterator first, InputIterator last, input_iterator_tag){
    iterator_traits<InputIterator>::different_type n = 0;
    while(first != last){
        ++first;
        ++n;
    }
    return n;
}

template <class RandomAccessIterator>
inline iterator_traits<RandomAccessIterator>::different_type 
__distance(RandomAccessIterator first, RandomAccessIterator last,
        randrom_access_iterator_tag){
    return last-first;
}

template <class InputIterator>
inline iterator_traits<InputIterator>::different_type
distance(InputIterator first, InputIterator last){
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    __distance(first, last, category());
}

//advace func
template <class InputIterator, class Distance>
inline void __advance(InputIterator& i, Distance n,
        input_iterator_tag){
    while(n--)
        ++i;
}

template <class BidirectIterator, class Distance>
inline void __advance(BidirectIterator& i, Distance n,
        bidirectional_iterator_tag){
    if(n >= 0)
        while(n--) ++i;
    else
        while(n++) --i;
}

template <class RandomAccessIterator, class Distance>
inline void __advance(RandomAccessIterator& i, Distance n,
        randrom_access_iterator_tag){
    i += n;
}

template <class InputIterator, Distance n>
inline void advance(InputIterator &i, Distance n){
    __advance(i, iterator_category(i));
}


