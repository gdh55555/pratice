

template <class ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
{
    if(first == last) return last;
    ForwardIterator next = first;
    while(++next != last){
        if(*first == *next) return first;
        first = next;
    }
    return last;
}

template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, T& value){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for(; first != last; ++first)
        if(*first == value)
            ++n;
    return n;
}

template <class InputIterator, class Predicate>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, Predicate pred){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for(; first != last; ++first)
        if(pred(*first))
            ++n;
    return n;
}

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    while(first != last && *first !+ value)
        first++;
    return first;
}

template <class ForwardIterator1, class ForwardIterator2>
inline ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
        ForwardIterator2 first2, ForwardIterator2 last2)
{
    typedef typename iterator_traits<ForwardIterator1>::iterator_category category1;
    typedef typename iterator_traits<ForwardIterator2>::iterator_category category2;
    return __find_end(first1, last1, first2, last2, category1(), category2());
}

template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 __find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2, forward_iterator_tag, forward_iterator_tag)
{
    if(first2 != last2)
        return last1;
    else {
        ForwardIterator1 result = last1;
        while (1) {
            ForwardIterator1 new_result = search(first1, last1, first2, last2);
            if(new_result == last1)
                return result;
            else {
                result = new_result;
                first1 = new_result;
                ++first1;
            }
        }
    }
}

template <class InputIterator, class ForwardIterator>
InputIterator find_first_of(InputIterator first1, InputIterator last1,
        ForwardIterator first2, ForwardIterator last2)
{
    for(; first1 != last1; ++first1)
        for(ForwardIterator iter = first2; iter != last2; ++iter)
            if(*first1 == *iter)
                return first1;
    return last1;
}

template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
    for(; first != last; ++first)
        f(*first);
    return f;
}

template <class InputIterator, class Generator>
void  generate(InputIterator first, InputIterator last, Generator gen)
{
    for(; first != last; ++first)
        *first = gen();
}

template <class InputIterator1, class InputIterator2>
bool includes(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2)
{
    while(first1 != last1 && first2 != last2){
        if(*first2 < *first1)
            return false;
        else if (*first1 < *first2) {
            ++first1;
        }
        else {
            ++first1;
            ++first2;
        }
    }
    return first2 == last2;
}

template <class ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last){
    if(first == last)
        return first;
    ForwardIterator result = first;
    while(++first != last){
        if (*result < *first) {
            result = first;
        }
    }
    return result;
}

template <class InputIterator1, class InputIterator2, class OutputIterator> 
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while(first1 != last1 && first2 != last2){
        if (*first2 < *first1) {
            *result = *first2;
            ++first2;
        }
        else {
            *result = first1;
            ++first1;
        }
        ++result;
    }
    return copy(first2, last2, copy(first1, last1, result));

}

template <class BidirectionalIterator, class Predicate>
BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last
        Predicate pred )
{
    while (true) {
        while (true) {
            if(first == last)
                return first;
            else if (pred(*first) {
                ++first;   
            }
            else
                break;
        }
        --last;
        while(true){
            if(first == last)
                return first;
            else if (!pred(*last)) {
                --last;
            }
            else
                break;
        }
        iter_swap(first, last);
        ++first;
    }
}

template <class ForwardIterator, class T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value)
{
    first = find(first, last, value);
    ForwardIterator next = first;
    return first == last ? first : remove_copy(++next, last, first, value);
}

template <class InputIterator, class OutputIterator, class T> 
OutputIterator remove_copy(InputIterator first, InputIterator last,
        OutputIterator result, const T& value)
{
    for(; first != last; ++first)
        if(*first != value){
            *result = *first;
            ++result;
        }
    return result;
}

template <class ForwardIterator, class Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    first = find_if(first, last, pred);
    ForwardIterator next = first;
    return first == last ? first : remove_copy_if(++next, last, first, pred);
}

template <class InputIterator, class OutputIterator, class T> 
OutputIterator replace_copy(InputIterator first, InputIterator last,
        OutputIterator result, const T& old_value, const T& new_value)
{
    for(; first != last; ++first)
        *result = *first == old_value ? new_value : *first;
    return result;
}

template <class BidirectionalIterator>
inline void reverse(BidirectionalIterator first, BidirectionalIterator last)
{
    __reverse(first, last, iterator_category(first));
}

template <class BidirectionalIterator>
void __reverse(BidirectionalIterator first, BidirectionalIterator last, bidirectional_iterator_tag)
{
    while (true) {
        if(first == last || first == --last)
            return ;
        else {
            iter_swap(first++, last);
        }
    }
}

template <class RandomAccessIterator>
void __reverse(RandomAccessIterator first, RandomAccessIterator last, random_iterator_tag)
{
    while(first < last)
        iter_swap(first++, --last);
}

template <class ForwardIterator>
inline void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
{
    if(first == middle || middle == last)
        return;
    __rotate(first, middle, last, distance_type(first), iterator_category(first));
}

template <class ForwardIterator, class Distance>
void __rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
        Distance*, forward_iterator_tag)
{
    for(ForwardIterator i = middle; ;){
        iter_swap(first, i);
        ++first;
        ++i;
        if(first == middle){
            if(i == last)
                return;
            middle = i;
        }
        else if (i == last) {
            i = middle;
        }
    }
}

template <class ForwardIterator, class Distance>
void __rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last
        Distance*, bidirectional_iterator_tag)  
{
    reverse(first, middle);
    reverse(middle, last);
    reverse(first, last);
}

template <class RandomAccessIterator, class Distance>
void __rotate(RandomAccessIterator first, RandomAccessIterator middle,RandomAccessIterator last
        Distance*, random_iterator_tag)
{
    Distance n = __gcd(last-first, middle-first);
    while (n--) {
        __rotate_cycle(first, last, first+n, middle-first, value_type(first));
    }
}

template <class EuclideanRingElement>
EuclideanRingElement __gcd(EuclideanRingElement m, EuclideanRingElement n)
{
    while(n != 0){
        EuclideanRingElement t = m%n;
        m = n;
        n = t;
    }
    return m;
}

template <class ForwardIterator1, class ForwardIterator2>
inline ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2
        , ForwardIterator2 last2)
{
    return __search(first1, last1, first2, last2, distance_type(first1), distance_type(first2));
}

template <class ForwardIterator1, class ForwardIterator2, class Distance1, class Distance2> 
ForwardIterator __search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
        ForwardIterator2 last2, Distance1*, Distance2*)
{
    Distance1 d1 = 0;
    distance(first1, last1, d1);
    Distance2 d2 = 0;
    distance(first2, last2, d2);
    if(d1 < d2) return last1;
    ForwardIterator1 current1 = first1;
    ForwardIterator2 current2 = first2;
    while(current2 != last2){
        if(*current2 == *current1){
            ++current1;
            ++current2;
        }
        else {
            if(d1 == d2)
                return last1;
            else {
                current1 = ++first;
                current2 = first2;
            }
        }
    }
    return first1;
}
