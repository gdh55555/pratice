#include <stdio.h>

int select(int a[], int l, int r){
    if(r <= l)
        return -1;
    int i = partition(a, l ,r);
    if(i < k)
        select(a, i+1, r, k);
    if(i > k)
        select(a, l, i-1, k);
}
