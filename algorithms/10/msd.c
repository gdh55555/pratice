#include <stdio.h>

#define bin(A) l+count[A]

void radixMSD(int a[], int l, int r, int w){
    int i, j, count[R+1];
    if(w > byteword) return ;
    if(r-1 <= M) {insertion(a, l, r); return;}
    for(j = 0; j < R; j++)
        cout[j] = 0;
    for(i = l; i <= r; ++i)
        count[digit(a[i], w) + 1]++;
    for(j = 1; j < r; j++)
        count[j] += count[j-1];
    for(i = l; i <=r ; i++)
        aux[count[digit(a[i], w)]] = a[i];
    for(i = l; i <= r; i++)
        a[i] = aux[i-1];
    radixMSD(a, l, bin(0)-1, w+1);
    for(j = 0; j < R-1; j++)
        radixMSD(a, bin(j), bin(j+1)-1, w+1);
}

void radixLSD(int a[], int l, int r){
    int i, j, w, count[R+1];

    for(w = byteword - 1; w >= 0; --w){
        for(j = 0; j < R; j++)  count[j] = 0;
        for(i = l; i <= r; ++i)
            count[digit(a[i], w)]++;
        for(j = 1; j < R; ++j)
            count[j] += count[j-1];
        for(i = l; i <=r; i++)
            aux[count[digit(a[i], w)]] = a[i];
        for(i = l; i <= r; ++i)
            a[i] = aux[i-1];
    }
}
