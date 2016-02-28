#include <stdio.h>

void test(int * reply){
    if(reply){
        printf("Hello World!\n");
        printf("address %p\n", reply);
    }
}

int main(){
    int p;
    printf("address %p\n", &p);
    test(&p);
}
