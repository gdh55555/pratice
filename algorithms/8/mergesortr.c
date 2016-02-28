#include <stdio.h>

int aux[maxN];

void mergesortABr(int a[], int b, int l, int r){
    int m = l + (r-l)/2;
    if(r-l <= 10)   {insertion(a,l,r); return;}
    mergesortABr(b, a, l, m);
    mergesortABr(b, a, m+1, r);
    mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

void mergesortAB(int a[], int l, int r){
    int i;
    for(i = l; i <= r; ++i) aux[i] = a[i];
    mergesortABr(a, aux, l ,r);
}
