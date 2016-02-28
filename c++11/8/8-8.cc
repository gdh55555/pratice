#include <iostream>
#include <type_traits>
using namespace std;

struct IntAligned{
    int a;
    char b;
};

typedef aligned_storage<sizeof(IntAligned), alignof(long double)>::type StrictAligned;

int main(){
    StrictAligned sa;
    IntAligned* pia = new(&sa) IntAligned;
    cout << alignof(IntAligned) << endl;
    cout << alignof(StrictAligned) << endl;
    cout << alignof(*pia) << endl;
    cout << alignof(sa) << endl;
}
