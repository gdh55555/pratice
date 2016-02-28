#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    typedef decltype(vec.begin()) vectype;

    for(vectype it = vec.begin(); it != vec.end(); ++it)
        //
        ;
    for(decltype(vec)::iterator it = vec.begin(); it != vec.begin(); ++it)
            //
            ;

}
