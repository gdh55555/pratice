#include <iostream>
using namespace std;

void f(char* p){
    cout << "invoke f(char*) " << endl;
}

void f(int ){
    cout << "invoke f(int) " << endl;
}

int main(){
    f(nullptr);
    f(0);
//    f(NULL);
    f((char*)0);
}
