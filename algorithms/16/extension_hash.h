#include <stdio.h>

typedef struct STnode* link;
struct STnode {item b[M]; int m; int k;};

static link *dir;
static int d, D, N;

link NEW(){
    link x = malloc(sizeof *x);
    x->m = 0;
    x->k = 0;
    return x;
}

void STinit(int maxN){
    d= 0;
    N = 0;
    D = 1;
    dir = malloc(D*(sizeof(*dir)));
    dir[0] = NEW();
}

Item search(lin h, Key v){
    int j;
    for(j = 0; j < h->m; j++)
        if(eq(v, key(h->b[j])))
            return h->b[j];
    return NULLitem;
}

link split(link h){
    int j;
    link t = NEW();
    while(h->m == 0 || h->m == M){
        h->m = 0;
        t->m = 0;
        for(j = 0; j< M; j++)
            if(bits(h->b[j], h->k, 1) == 0)
                h->b[(h->m)++] = h->b[j];
            else
                t->b[(t->m)++] = h->b[j];
        t->k = ++(h->k);
    }
    insertDir(t, t->k);
}

void insert(link h, Item item){
    int i, j;
    Key v = key(item);
    for(j =0; j < h->m; ++j)
        if(less(v, key(h->b[j])))
            break;
    for(i = (h->m)++; i> j; i--)
        h->b[i] = h->b[i-1];
    h->b[j] = item;
    if(h->m == M)   split(h);
}

void insertDir(link t, int k){
    int i, m, x= bits(t->b[0], 0, k);
    while(d < k){
        link* old = dir;
        d += 1;
        D +=D;
        dir = malloc(D*sizeof(*dir));
        for(i = 0; i < D; ++i)
            dir[i] = old[i/2];
        if(d < k)
            dir(bits(x, 0, d) ^ 1) = NEW();
    }
    for(m = 1; k <d; ++k) m *= 2;
    for(i = 0; i < m; i++)  dir[x*m+1] = t;
}
