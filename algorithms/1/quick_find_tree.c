#include <stdio.h>

#define N 10

int main(int argc, char** argv)
{
    int k, i, j, q, p, t , id[N];

    for(i = 0; i < N; ++i) id[i] = i;

    while (2 ==scanf("%d %d\n", &p, &q ))
    {
        if(id[q] == id[p]) continue;
        for(i =p; i != id[i]; i = id[i]) ;
        for(j =q; j != id[j]; j = id[j]) ;
        if (i == j) continue;
        id[i] = j;

        /*if(id[i] == t) id[i] = id[q];*/
        //printf("%d %d\n", p, q);
    }
    for(i = 0; i < N; ++i) printf("%d ",id[i]);
    printf("\n");
}
