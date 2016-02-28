#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template <class T>
struct display {
    void operator()(const T& x) const{
        cout << x << ' ';
    }
};

int main(void)
{
    int ia[9] = {0 , 1, 2, 3 ,4, 5, 6, 7, 8 };
    vector<int> iv1(ia, ia+5);
    vector<int> iv2(ia, ia+9);

    cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).first);
    cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).second);

    cout << equal(iv1.begin(), iv1.end(), iv2.begin()) ;
    cout << equal(iv1.begin(), iv1.end(), &ia[3]) ;


    cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>()) ;

    fill(iv1.begin(), iv1.end(), 9);
    for_each(iv1.begin(), iv1.end(), display<int>());

    fill_n(iv1.begin(), 3, 7);
    for_each(iv1.begin(), iv1.end(), display<int>());

    vector<int>::iterator ite1 = iv1.begin();
    vector<int>::iterator ite2 = ite1;

    advance(ite2, 3);
    iter_swap(ite1, ite2);

    cout << *ite1 << ' ' << *ite2 << endl;

    for_each(iv1.begin(), iv1.end(), display<int>());



    return 0;
}
