#include <stdio.h>
#include "merge.h"

void mergesort(int a[], int l, int r){
    int m = l + (r-l)/2;
    if(r <= l)  return ;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}
