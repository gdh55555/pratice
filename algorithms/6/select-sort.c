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
