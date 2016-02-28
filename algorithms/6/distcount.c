#include <stdio.h>
#include <stdlib.h>
#define M 100

void distcount(int a[], int l, int r){
    int i, j, cnt[M], b[M];
    for(j = 0; j < M; ++j) cnt[j] = 0;
    for(j = 0; j < M; ++j) b[j] = 0;
    for(i = l; i <= r; ++i) cnt[a[i]+1]++;
    
    for(j = 1; j < M; ++j) cnt[j] += cnt[j-1];
    for(i = l; i <= r; ++i) b[cnt[a[i]]++] = a[i];
    for(i = l; i <= r; ++i) a[i] = b[i];

}

void countsort(int a[], int l, int r){
    int i, j, cnt[M], b[M];
    for(j = 0; j < M; ++j) cnt[j] = 0;
    for(j = 0; j < M; ++j) b[j] = 0;
    for(i = 0; i <= r; ++i) cnt[a[i]]++;
    for(j = 1; j <= M; ++j) cnt[j] += cnt[j-1];
/*    for(int i = 0; i <= 14; ++i)
        printf("%d ", a[i]);
    printf("\n");
*/  
    for(j = r; j >= l; --j){
       b[--cnt[a[j]]] = a[j]; 
    }
    for(i = l; i <= r; ++i){ 
        printf("%d ", b[i]);
        a[i] = b[i];
    }
    printf("\n");

}
int main(){
    int a[] = {0, 3, 3, 0, 1, 1, 0, 3, 0, 2, 0, 1, 1, 2,0};
    distcount(a, 0, 14);
    //countsort(a, 0, 14);
    for(int i = 0; i <= 14; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
