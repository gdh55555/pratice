
template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result){
    for(; first != last; ++first; ++result)
        *result = *first;
    return result;
}

template <class T> class ostream_iterator{
    private:
        ostream* os;
        const char* string;
    public:
        ostream_iterator(ostream& s, const char* s = 0) : os(&s), string(c){}

        ostream_iterator& operator=(const ostream_iterator& i){
            os = i.os;
            string = i.string;
            return *this;
        }

        ostream_iterator<T>& operator=(const T& value){
            *os << value;
            if(string)
                *os << string;
            return *this;
        }

        ostream_iterator<T>& operator*(){ return *this;}
        ostream_iterator<T>& operator++(){ return *this;}
        ostream_iterator<T>& operator++(this){ return *this;}

};

template <class ForwardIterator, class T>
void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value){
    for(; first != last; ++first){
        if(*first == old_value)
            *first = new_value;
    }
}

template <class ForwardIterator>
ForwardIterator
adjacent_find(ForwardIterator first, ForwardIterator last){
    if(first == last)
        return first;
    ForwardIterator next = first;
    while(++next != last){
        if(*first == *next)
            return first;
        first = last;
    }
    return last;
}

template <class BidirectionalIterator, class OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result){
    while(fisrt != last){
        --last;
        *result = *last;
        ++result;
    }
    return result;
}


