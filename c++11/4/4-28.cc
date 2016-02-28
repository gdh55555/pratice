#include <iostream>
#include <type_traits>
using namespace std;

int i = 1;
int& j = i;
int* p = &i;
const int k = 1;
int main(){
    decltype(i)& var1 = i;
    decltype(j)& var2 = i;

    cout << is_lvalue_reference<decltype(var1)>::value << endl;
    cout << is_lvalue_reference<decltype(var2)>::value << endl;
    cout << is_rvalue_reference<decltype(var2)>::value << endl;


    decltype(p)* var3 = &p;

    auto* v3 = p;
    v3 = &i;

    const decltype(k) var4 = 1;
}
