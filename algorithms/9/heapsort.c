#include <stdlib.h>

void heapsort(int a[], int l, int r){
    int k,N = r-l+1; int* pq = a+l-1;
    for(k = N/2, k >= 1; k--)
        fixDown(pq, k, N);
    while(N > 1){
        swap(pq[1], pq[N]);
        fixDown(pq, 1, --N);
    }
}
