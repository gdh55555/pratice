#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec;
    list<int> li;
    int i;
    while( cin >> i)
        li.push_back(i);
    vec.resize(li.size());
    fill_n(vec.begin(), li.size(), 0);
    for(i = 0; i < vec.size();++i)
        cout << vec.at(i) << " ";
    cout << endl;

    copy(li.cbegin(), li.cend(), vec.begin());
    for(i = 0; i < vec.size();++i)
        cout << vec.at(i) << " ";
    cout << endl;

}
