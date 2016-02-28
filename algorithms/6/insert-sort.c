#include <stdio.h>
#include <stdlib.h>

void insection(int a[], int l, int r){
    if(l > r)
        return;
    int i, j;
    for(i = l+1; i <= r; ++i ){
        int b = a[i];
        int j = i;
        while(a[j] <= b){
            a[j] = a[j-1];
            --j;
        }
        a[j] = b;
    }
#include <stdio.h>
#include <stdlib.h>

void selection(int a[], int l, int h){
    if(l > h)
        return;
    int i, j;
    for(int i = l; i < h, i++){
            int min = i
            for(j = i + 1; j <= h; ++j){
                        if(a[i] > a[j])
                            min = j;
                    }
            swap(a[i], a[min]);
        }
}
}
