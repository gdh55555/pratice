#include <stdio.h>
#include <stdlib.h>

void shellsort(int a[], int l, int r){
    int i, j, h;
    for(h = 1; h <= (r-1)/9; h = 3*h + 1) ;
    for(; h>0; h /=3)
        for(i  = l+h;; i <= r; ++i)
        {
            int j = i;
            int v = a[i];
            while(j>=l+h && a[j-h] > v){
                a[j]=a[j-h];
                j -=h;
            }
            a[j] = v;
        }
}
