#include <stdio.h>
#include <stdlib.h>

#define eq(A,B) (!less(A,B) && ! less(B,A))

void quicksort(int a[], int l, int r){
    int i, j, k, p, q;
    int v;
    v = a[r];
    i = l-1;
    j = r;
    p = l-1;
    q = r;
    while(true){
        while(less(a[++i], v)) ;
        while(less(v, a[--j])) if(j == l ) break;
        if(i >= j )
            break;
        swap(a[i],a[j]);
        if(eq(a[i], a[r])) {p++; swap(a[p], a[i]);}
        if(eq(v, a[j])) {q--; swap(a[q], a[j]);}

    }
    swap(a[i], a[j]);
    j = i-1;
    i++;
    for(k = 1; k < p; k++, j--)
        swap(a[k], a[j]);
    for(k = r-1; k > q; k--,i++)
        swap(a[k], a[i]);
    quicksort(a, l, j);
    quicksort(a, i, r);
}
