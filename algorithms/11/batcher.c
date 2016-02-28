#include <stdio.h>

mergeTD(int a[], int l, int r){
    int i, m = (l+r)/2;
    if(r == l+1) compexch(a[l], a[r]);
    if(r < l+2) return ;
    unshuffle(a, l, r);
    mergeTD(a, l, m);
    mergeTD(a, m+1, r);
    shuffle(a, l, r);
    for(i = l + 1; i < r; i+=2)
        compexch(a[i], a[i+1]);
}

mergeBU(int a[], int l, int r){
    int i, j, k, N = r-l+1;
    for(k = N/2; k > 0; k /= 2)
        for(j = k % (N/2); j+k < N; j +=(k+k))
            for(i = 0; i < k; i++)
                compexch(a[l+j+i], a[l+j+i+k]);
}
