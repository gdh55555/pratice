#include <stdio.h>

int select(int a[], int l, int r, int k){
    while(l <= r){
        int i = partition(a, l, r);
        if(i < k)
            l = i+1;
        if(i > k)
            r = i-1
    }
}
