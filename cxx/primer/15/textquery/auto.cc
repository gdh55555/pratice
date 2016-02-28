#include <iostream>
#include <string>

using namespace std;

auto getString( string s){
    return s;
}

int main(int argc, char* argv[]){
    if(argc == 1)
        cout << getString("Hello");
    else
        cout << getString(argv[1]);
    cout << endl;
    return 0;
}
