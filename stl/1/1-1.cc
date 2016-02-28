#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>

using namespace std;

int main(){
    vector<string> v;
    string tmp;
    while(getline(cin, tmp))
        v.push_back(tmp);
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}
