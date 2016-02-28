#include <iostream>
using namespace std;

template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last,
        Predicate pred){
    while(first != last && !pre(*first))
        ++first;
    return first;
}

bool is_even(int x){
    return (x & 1) == 0;    
}

find_if(f, L, is_even);

template <class ForwardIterator, class BinaryPredicate>
ForwardIterator 
adjacent_find(ForwardIterator first, ForwardIterator last,
        BinaryPredicate pred){
    if(first == last)
        return last;
    ForwardIterator next = first;
    while(++next != last){
        if(pred(*first, *next))
            return first;
        first = next;
    }
    return last;
}

template <class InputIterator, class OutputIterator, class UnaryFunction>
OutputIterator transform(InputIterator first, InputIterator last,
        OutputIterator result, UnaryFunction f){
    while(first != last)
        *result++ = f(*first++);
    return result;
}


