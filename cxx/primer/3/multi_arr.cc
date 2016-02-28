#include <iostream>
using namespace std;


int main()
{
int ia[3][4] = {
    {1,2,3,4},
    {1,2,3,4},
    {1,1,1,1}
};
    for(auto p = ia; p != ia+3; ++p)
        for(auto q = *p; q != *p+4; ++q)
            cout << *q << " ";
        cout << endl;
    cout << endl;

    for(auto p = begin(ia); p != end(ia); ++p)
        for(auto q = begin(*p); q != end(*p); ++q)
            cout << *q << " ";
        cout << endl;
    cout << endl;

    using int_arr=int[4];

    for (int_arr *p = ia; p != ia+3; ++p)
        for(int *q = *p; q != *p +4; ++q)
             cout << *q << " ";
        cout << endl ;
    cout << endl;
    return 0;
}
