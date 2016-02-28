#include <iostream>

using namespace std;

union T{
    string s;
    int n;
public:
    T(){new (&s) string;}
    ~T(){s.~string();}
};

int main(){
    T t;
}
