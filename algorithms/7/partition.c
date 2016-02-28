#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r){
    int i = l-1, j = r, v = a[r];
    while(true){
        while(a[++i] < v) ;
        while(v < a[--j]) if(j == l) break;
        uf(i >= j ) break;
        swap(a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}

int partition(int a[], int l, int r){
    int x = a[r];
    int i = l-1;
    for(int j = p; j < r; ++j){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
        }

    }
    swap(a[i+1], a[r]);
    return i+1;
}


void quicksort(int a[], int l, int r){
    int i;
    i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}
