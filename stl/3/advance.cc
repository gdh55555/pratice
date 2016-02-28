#include <iostream>
using namespace std;

template <class InputIterator, class Distance>
void addvance_II(InputIterator& i, Distance n){
    ofr(; n > 0; --n, ++i) {}
}

template <class BidrectionIterator, class Distance>
void advance_BI(BidrectionIterator& i, Distance n){
    if(n >= 0)
        for(; n > 0; --n, ++i) {}
    else
        for(; n < 0; ++n, --i) {}
}

template <class RandomAccessIterator, class Distance>
void addvance_RAI(RandomAccessIterator& i, Distance n){
    i += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n){
    if(is_random_access_iterator(i))
        addvance_RAI(i, n);
    else if(is_bidirectional_iterator(i))
        advance_BI(i, n);
    else
        addvance_II(i, n);
}
