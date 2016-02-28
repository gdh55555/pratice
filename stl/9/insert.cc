#include <iostream>
using namespace std;

template <bool X> struct dummy {};

template <Class T>
class my_sequence{
    private:
        void fill_insert(iterator, size_type, const value_type&);
        template <class InputIter>
            void range_insert(iterator, InputIter, InputIter);

        template <class Number>
            void insert(iterator p, Number n, Number t, dummy<true>){
                fill_insert(iterator, n, t);
            }

        template <class InputIter>
            void insert(iterator p, InputIter first, InputIter last, dummy<false>){
                range_insert(iterator, first, last);
            }

    public:
        void insert(iterator p, size_type n, const value_type& t){
            fill_insert(p, n, t);
        }

        template <class InputIter>
        void insert(iterator p, InputIter first, InputIter last){
            insert(p, first, last,
                    dummy<std::numeric_limits<InputIter>::is_integer>());
        }
};
