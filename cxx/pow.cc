#include <iostream>
#include <algorithm>
using namespace std;

double myPow(double x, int n) {
    if(n==0)
        return 1.0;
    if(n<0){
        cout << 11 << endl;
        return 1.0/myPow(x,abs(n));
    }
    return (n&1) ? pow(myPow(x,n/2),2)*x : pow(myPow(x,n/2),2);
}

int main(){
    int n;
    double x;
    while(cin >> x >> n){
        cout << myPow(x, n) << endl;
    }
}

