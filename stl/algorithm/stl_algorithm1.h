
template <class ForwardIterator, class T>
inline ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value)
{
    return __lower_bound(first, last, value, distance_type(first), iterator_category(first));
}

template <class ForwardIterator, class T, class Distance> 
ForwardIterator __lower_bound(ForwardIterator first, ForwardIterator last,
        const T& value, Distance*, forward_iterator_tag)
{
    Distance len = 0;
    distance(first, last, len);
    Distance half;
    ForwardIterator middle;

    while (len > 0) {
        half = len >> 1;
        middle = first;
        advance(middle, half);
        if(*middle < value){
            first = middle;
            ++first;
            len = len - half -1;
        }
        else {
            len = half;
        }
    }
    return first;
}

template <class ForwardIterator, class T, class Distance> 
ForwardIterator __upper_bound(ForwardIterator first, ForwardIterator last,
        const T& value, Distance*, forward_iterator_tag)
{
    Distance len = 0;
    distance(first, last, len);
    Distance half;
    ForwardIterator middle;

    while (len > 0) {
        half = len >> 1;
        middle = first;
        advance(middle, half);
        if(*middle > value){
            len = half;
        }
        else {
            first = middle;
            ++first;
            len = len-half-1;
        }
    }
    return first;
}

template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value)
{
    ForwardIterator i = lower_bound(first, last, value);
    return i != last && !(value < *i);
}

template <class BidirectionalIterator>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
    if(first == last) return false;
    BidirectionalIterator i = first;
    ++i;
    if( i == last) return false;
    i = last;
    --i;
    for(;;){
        BidirectionalIterator ii = i;
        --i;
        if(*i < *ii){
            BidirectionalIterator j = last;
            while(!(*i < *--j)) ;
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if(i == first){
            reverse(first, last);
            return false;
        }
    }
}

template <class BidirectionalIterator>
bool prev_premutation(BidirectionalIterator first, BidirectionalIterator last)
{
    if(first == last) return false;
    BidirectionalIterator i = first;
    ++i;
    if(i == last) return false;
    i = last;
    --i;

    while (true) {
        BidirectionalIterator ii = i;
        --i;
        if(*i > *ii){
            BidirectionalIterator j = last;
            while(!(*i > *--j)) ;
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == last) {
            reverse(first, last);
            return false;
        }
    }
}

template <class RandomAccessIterator>
inline void random_shuffle(RandomAccessIterator first, RandomAccessIterator last)
{
    __random_shuffle(first, last, distance_type(first));
}

template <class RandomAccessIterator, class Distance>
void __random_shuffle(RandomAccessIterator first, RandomAccessIterator last, Distance*)
{
   if(first == last) return;
   for(RandomAccessIterator i = first + 1; i != last; ++i){
       iter_swap(i, first+Distance(rand()% ((i-first)+1)));
   }
}

template <class RandomAccessIterator>
inline void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
{
    __partial_sort(first, middle, last, value_type(first));
}

template <class RandomAccessIterator, class T>
void __partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, T*)
{
    make_heap(first, middle);
    for(RandomAccessIterator i = middle; i < last; i++)
        if(*i < *first)
            __pop_heap(first, middle, i, T(*i), distance_type(first));
    sort_heap(first, last);
}

template <class RandomAccessIterator>
void __insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last) {
        return ;
    }
    for(RandomAccessIterator i = first + 1; i != last; ++i)
        __linear_insert(first, i, value_type(first));
}

template <class RandomAccessIterator, class T>
inline void __linear_insert(RandomAccessIterator first, RandomAccessIterator last, T*)
{
    T value = *last;
    if (value < *first) {
        copy_backward(first, last, last+1);
        *first = value;
    }
    else {
        __unguarded_linear_insert(last, value);
    }
}

template <class RandomAccessIterator, class T>
void __unguarded_linear_insert(RandomAccessIterator last, T value)
{
    RandomAccessIterator next = last;
    --next;
    while (value < *next) {
        *last = *next;
        last = next;
        --next;
    }
    *last = value;
}

template <class T>
inline const T& __median(const T& a, const T& b, const T& c)
{
    if(a < b)
        if(b < c)
            return b;
        else if (a < c) {
            return c;
        }
        else
            return a;
    else if(a < c)
        return a;
    else if(b < c)
        return c;
    else 
        return b;
}

template <class RandomAccessIterator, class T>
RandomAccessIterator __unguarded_partiton(RandomAccessIterator first, RandomAccessIterator last, T pivot)
{
    while (true) {
        while (*first < pivot) {
            ++first;
        }
        --last;
        while(*last > pivot)
            --last;
        if(!(first < last))return first;
        iter_swap(first, last);
        ++first;
    }
}

template <class RandomAccessIterator>
inline void sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if(first != last){
        __introsort_loop(first, last, value_type(first), __lg(last-first)*2);
        __final_insertion_sort(first, last);
    }
}

template <class Size>
inline Size __lg(Size n)
{
    Size k;
    for(k = 0; n > 1; n >>= 1) ++k;
    return k;
}

// __stl_threshold = 16
template <class RandomAccessIterator, class T, class Size> 
void __introsort_loop(RandomAccessIterator first, RandomAccessIterator last, T*, Size depth_limit)
{
    while (last - first > __stl_threshold) {
        if(depth_limit == 0){
            partial_sort(first, last, last);
            return;
        }
        --depth_limit;
        RandomAccessIterator cut = __unguarded_partiton
            (first, last, T(__median(*first, *(first +(last-first)/2), *(last-1))));
        __introsort_loop(cut, last, value_type(first), depth_limit);
        last = cut;
    }
}

template <class RandomAccessIterator>
void __final_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if(last - first > __stl_threshold ){
        __insertion_sort(first, first + __stl_threshold);
        __unguarded_insertion_sort(first+__stl_threshold, last);
    }
    else {
        __insertion_sort(first, last);
    }
}

template <class RandomAccessIterator>
inline void __unguarded_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    __unguarded_insertion_sort_aux(first, last, value_type(first));
}

template <class RandomAccessIterator, class T>
void __unguarded_insertion_sort_aux(RandomAccessIterator first, RandomAccessIterator last, T*)
{
    for(RandomAccessIterator i = first; i != last; ++i)
        __unguarded_linear_insert(i, T(*i));
}

template <class ForwardIterator, class T>
inline pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& value)
{
    return __equal_range(first, last, value, distance_type(first), iterator_category(first));
}

template <class RandomAccessIterator, class T, class Distance> 
pair<RandomAccessIterator, RandomAccessIterator>
__equal_range(RandomAccessIterator first, RandomAccessIterator last, const T& value, Distance*, random_access_iterator_tag){
    Distance len = last - first;
    Distance half;
    RandomAccessIterator middle, left, right;

    while (len < 0) {
        half = len >> 1;
        middle = first + half;
        if(*middle < value){
            first = middle + 1;
            len = len-half-1;
        }
        else if(value < *middle)
            len = half;
        else {
            left = lower_bound(first, middle, value);
            // ForwardIterator
            // advance(first, len);
            right = upper_bound(++middle, first + len, value);
            return pair<RandomAccessIterator, RandomAccessIterator>(left, right);
        }
        return pair<RandomAccessIterator, RandomAccessIterator>(first, first);
    }
}

template <class BidirectionalIterator>
inline void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
{
    if(first == middle || middle == last) return;
    __inplace_merge_aux(first, middle, last, value_type(first), distance_type(first));
}

template <class BidirectionalIterator, class T, class Distance> 
inline void __inplace_merge_aux(BidirectionalIterator first, BidirectionalIterator middle,
        BidirectionalIterator last, T*, Distance*)
{
    Distance len1 = 0;
    distance(first, middle, len1);
    Distance len2 = 0;
    distance(middle, last, len2);

    temporary_buffer<BidirectionalIterator, T> buf(first, last);
    if(buf.begin() == 0)
        __merge_without_buffer(first, middle, last, len1, len2);
    else
        __merge_adaptive(first, middle, last, len1, len2, buf.begin(), Distance(buf.size()));
}

template <class BidirectionalIterator, class Distance, class Pointer> 
void __merge_adaptive(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last
        Distance len1, Distance len2, Pointer buffer, Distance buffer_size)
{
    if (len1 <= len2 && len1 <= buffer_size) {
        Pointer end_buffer = copy(first, middle, buffer);
        merge(buffer, end_buffer, middle, last, first);
    }
    else if (len2 <= buffer_size) {
        Pointer end_buffer = copy(middle, last, buffer);
        __merge_backward(first, middle, buffer, end_buffer, last);
    }
    else {
        BidirectionalIterator first_cut = first;
        BidirectionalIterator second_cut = middle;

        Distance len11 = 0;
        Distance len22 = 0;
        
        if(len1 > len2){
            len11 = len1 >>1;
            advance(first_cut, len11);
            second_cut = lower_bound(middle, last, *first_cut);
            distance(middle, second_cut, len22);
        }
        else {
            len22 = len2 / 2;
            advance(second_cut, len22);
            first_cut = upper_bound(first, middle, *second_cut);
            distance(first, first_cut, len11);
        }
        BidirectionalIterator new_middle = __rotate_adaptive(first_cut, middle, second_cut, len1 - len11, len22, buffer, buffer_size);
        __merge_adaptive(first, first_cut, new_middle, len11, len22, buffer, buffer_size);
        __merge_adaptive(new_middle, second_cut, last, len1-len11, len2-len22, buffer, buffer_size);
    }
}
