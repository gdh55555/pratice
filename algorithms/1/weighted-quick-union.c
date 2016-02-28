#include <stdio.h>
#define N 10

int main(int argc, char ** argv)
{
    int i, j, p, q, id[N], sz[N];
    for(i = 0; i < N; ++i) 
    {
        id[i] = i;
        sz[i] = 1;
    }

    while(2 == scanf("%d %d\n", &p, &q))
    {
        for(i = p; i != id[i]; i = id[i] );
        for(j = q; j != id[j]; j = id[j] );
        
        if(i == j) continue;
        if(sz[i] > sz[j])
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        else
        {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
}
