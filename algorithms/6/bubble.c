#include <stdio.h>
#include <stdlib.h>

void bubble(int a[], int l, int r){
    int i, j;
    bool flag = true;
    for(i = l; i < r; ++i)
        if(flag){
            flag = false;
            for(j = r; j > l; --j)
                if(a[j] < a[j-1]){
                    swap(a[j], a[j-1]);
                    flag = true;
                }
        }
}
