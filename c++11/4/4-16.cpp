#include <iostream>
#include <typeinfo>
using namespace std;

class White{};
class Black{};

int main(){
    White a;
    Black b;

    cout << typeid(a).name() << endl;
    cout << typeid(a).name() << endl;

    White c;

    bool a_b_sametype = (typeid(a)).hash_code() == (typeid(b)).hash_code();
    bool a_c_sametype = (typeid(a)).hash_code() == (typeid(c)).hash_code();

    cout << "Same type ?" << endl;

    cout << "A and B ?" << a_b_sametype << endl;
    cout << "A and C ?" << a_c_sametype << endl;
}
