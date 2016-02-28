#include <stdio.h>
#include <stdlib.h>

#define push(A,B) push(B);push(A);

void quciksort(int a[], int l, int r)
{
    int i;
    stack s;
    push(l, r);
    while(!isempty(s)){
        l = pop();
        r = pop();
        if(r <= l) continue;
        i = partition(a, l, r);
        if(i-l > r-i){
            push(l,i-1);
            push(i+1, r);
        }
        else{
            push(i+1, r);
            push(l, i-1);
        }
    }
}
