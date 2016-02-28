#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vecStr;
    string str;
    while(cin >> str)
        vecStr.push_back(str);
    for(auto c:vecStr)
        cout << c << endl;
    return 0;
}
