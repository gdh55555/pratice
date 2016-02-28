#include <stdlib.h>

static int* pq;
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
    fixUp(pq, N);
}

int PQdelmax(){
    swap(pq[1], pq[N]);
    fixDown(pq, 1, N-1);
    return pq[N--];
}
