#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<string> res = {"12", "123", "1", "4", "0"};
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    sort(res.begin(), res.end(), greater<string>());
    for(auto i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
