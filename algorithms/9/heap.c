#include <stdlib.h>

void fixUp(int a[], int k){
    while(k >l && less(a[k/2], a[k])){
        swap(a[k], a[k/2]);
        k /= 2;
    }
}

void fixDown(int a[], int k, int N){
    int j;
    while(2*k < N){
        j = 2*k;
        if(j < N && less(a[j], a[j+1])) j++;
        if(!less(a[k], a[j]))   break;
        swap(a[j], a[k]);
        k = j;
    }
}
