#include <iostream>

using namespace std;

template <class InputIterator>
typename iterator_traits<InputIterator>::value_type
sum_nonempty(InputIterator first, InputIterator last){
    typename iterator_traits<InputIterator>::value_type result = *first++;
    for(;first != last; ++first)
        result += *first;
    return result;
}

template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T& x){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for(;first != last; ++first)
        if(*first == x)
            ++n;
    return n;
}
