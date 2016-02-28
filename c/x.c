#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int x;
    while(cin >> x){
        printf("%0x %0x ", x, -x);
        cout << (x&-x) << endl ;
    }
}
