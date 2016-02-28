#include <iostream>
#include <string>

using namespace std;

string getName(){
    return "gugu";
}

int main(){
    const string &name = getName();
    string &&sname = getName();
    cout << name << endl;
    cout << sname << endl;
}
