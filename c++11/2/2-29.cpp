#include <iostream>
using namespace std;

template<class T, class U = double>
void f(T t = 0, U u = 0){
    cout << "t: " << t <<
        "u: " << u <<endl;
}

void g(){
    f(1, 'c');
    f(1);
    f<int>();
    f<int, char>();
}

int main(){
    g();
}
