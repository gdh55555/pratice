#include <stdio.h>

#define N 10

int main(int argc, char** argv)
{
    int i, q, p, t , id[N];
    
    for(i = 0; i < N; ++i) id[i] = i;

    while (2 ==scanf("%d %d\n", &p, &q ))
    {
        if(id[q] == id[p]) continue;

        for(t = id[p], i =0; i < N; ++i)
        {
            if(id[i] == t) id[i] = id[q];
            //printf("%d %d\n", p, q);
        }
    }
    for(i = 0; i < N; ++i) printf("%d ",id[i]);
    printf("\n");
}
