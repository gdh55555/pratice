#include <stdio.h>
#include <time.h>
#define N 1000

int main()
{
    int a[N], i;

    srand((unsigned ) time(0));
    for(i = 0; i < N; i++) a[i] = 0;
    for(i = 1; ; i++)
    {
        int curr = rand() % 1000;
        if(++a[curr] == 2)
            break;
    }

    printf("The total count is %d \n", i);
    return 0;
}
