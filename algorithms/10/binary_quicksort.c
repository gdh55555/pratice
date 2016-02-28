#include <stdio.h>

quicksortB(int a[], int l, int r, int w){
    int i = l;
    int j = r;
    if(r <= l || w > bitword)
        return ;

    while(i != j){
        while(digit(a[i], w) == 0 &&(i < j)) i++;
        while(digit(a[j], w) == 1 &&(i < j)) j--;
        swap(a[i], a[j]);
    }

    if(digit(a[r], w) == 0)
            j++;
    quicksortB(a, l, j-1, w+1);
    quicksortB(a, j, r, w+1);
}

void sort(int a[], int l, int r){
    quicksortB(a, l, r, 0);
}
