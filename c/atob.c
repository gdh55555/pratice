#include <stdlib.h>
#include <stdio.h>

typedef struct A{
    int a;
}A;

typedef struct B{
    A a;
    int b;
}B;

void init(A** a){
    B* b;
    b = malloc(sizeof *b);
    b->a.a = 1;
    *a = &b->a;
    b->b = 2;
}

void transfer(A* a){
    B* b = (B*)a;
    if(b->a.a){
        printf("%d\n", b->a.a);
    }
    if(b->b){
        printf("%d\n", b->b);
    }
}

int main(){
    A* a;
    init(&a);
    transfer(a);
}
