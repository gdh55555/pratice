#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void biggies(vector<int>& word, 
        vector<int>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), 
            [](const string& a, const string& b){return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(), 
            [sz](const string &a){ return a.size() > sz;});
    for_each(wc , words.end(),
            [](const string &s){cout << s << " ";});
    cout << endl;
}
