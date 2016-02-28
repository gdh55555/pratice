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
            sz[i] += sz[j];
            for(j = q; ; j = id[j] )
            {
                id[j] = i;
                if(j == id[j])
                    break;
            }
        }
        else
        {
            sz[j] += sz[i];
            for(i = p; ; i = id[i] )
            {
                id[i] = j;
                if(i == id[i])
                    break;
            }
        }
    }
    for(i = 0; i < N; ++i) 
    {
        printf("%d  ", id[i]);
    }
    printf("\n");
    for(i = 0; i < N; ++i) 
        printf("%d  ", sz[i]);
}
