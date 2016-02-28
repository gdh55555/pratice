#include <stdio.h>

#define min(A,B) (A<B)?A:B

void mergesortBU(int a[], int l, int r){
    int i, m;
    for(m = 1; m <= r-1; m *=2)
        for(i = 1; i <= r-m; i+= m+m)
            merge(a, i, i+m-1, min(i+m+m-1, r));
}
