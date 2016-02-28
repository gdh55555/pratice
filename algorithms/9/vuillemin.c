#include <stdio.h>

PQlink PQinsert(PQ pq, int v){
    int i;
    PQlink c, t = malloc(sizeof *t);
    c = t; c->l  = z;
    c->r = z;
    c->key = v;
    for(i = 0; i< maxBQsize; i++){
        if(c == z)  break;
        if(pq->bq[i] == z)
        {
           pq->bq[i] = c;
           break;
         }
        c = pair(c, pq->bq[i]);
        pq->bq[i] = z;
    }
}
