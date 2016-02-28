#include <stdio.h>
#include <stdlib.h>

mergeAB(int c[], int a[], int N, int b[], int M){
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < N+N; k++){
        if(i == N){c[k] = b[j++]; continue;}
        if(j == M){c[k] = b[i++]; continue;}
        c[k] = (less(a[i], b[j]) ? a[i+] : b[j++];
    }
}
