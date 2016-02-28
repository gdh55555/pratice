#include <iostream>
#include <vector>
#include <deque>
#include <list

using namespace std;

class TDConstructed{
    template<class T> TDConstructed(T first, T end): l(first,end){}
    list<int> l;
    public:
    TDConstructed(vector<short>& v ) : TDConstructed(v.begin(), v.end()){}
    TDConstructed(deque<int>& d) : TDConstructed(d.begin(), d.end()){}
};


