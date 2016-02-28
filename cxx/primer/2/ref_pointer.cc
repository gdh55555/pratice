#include <iostream>
using namespace std;

int main()
{
    int i = 42;
    cout << "i = " << i << endl;
    int* p = &i;
    int *&rp = p;
    int j = 12;
    rp = &i;
    cout << "i = " << i << " *p " << *p << endl;
    *rp = 0;
    cout << "i = " << i << " *p " << *p << endl;
    return 0;
}
