#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >>n;
    double res = 1;
    while(n--)
        res *= 2;
    printf("%.01f\n", res);
}
