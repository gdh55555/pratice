#include <stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int *)b - *(int*)a;   
}

int main()
{
    int a[] = {1,3,6,5,0};
    qsort(a,5,sizeof(a[0]),cmp);
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i] );
    printf("\n");
    return 0;
}
