#include <stdlib.h>

static int *pq;
static int N;

void PQinit(int maxN){
    pq = malloc(maxN*sizeof(int));
    N = 0;
}

int PQempty(){
    return N == 0;
}

void  PQinsert(int v)
{
    pq[N++] = v;
}

int PQdelmax(){
    int j, max = 0;
    for(j = 1; j < N; j++){
        if(pq[max] < pq[j])
            max = j;
    }
    swap(pq[max], pq[N-1]);
    return pq[--N];
}
