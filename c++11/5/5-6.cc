#include <iostream>
using namespace std;

enum class C : char {C1 = 1, C2};
enum class D: unsigned int {D1 = 1, D2, Dbig = 0xFFFFFFF0U};

int main(){
    cout << sizeof(C::C1) << endl;
    cout << (unsigned int)D::Dbig << endl;
    cout << sizeof(D::Dbig) << endl; 
}
