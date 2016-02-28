#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;
    cin >> str1;
    const string str = "hello world";
    for(auto& c: str)
    {
        c = 'X';
    }
    cout << str << endl;
    return 0;
}
