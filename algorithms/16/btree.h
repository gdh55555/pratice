#include <stdio.h>

typedef struct STnode* link;
typedef struct{Key Key; union{link next; Item item}ref;}entry;

struct STnode{enty b[M]; int m;};

static link head;
static int H, N;
link NEW(){
    link x = malloc(sizeof *x);
    x->m = 0;
    return x;
}

void STinit(int maxN){
    head = NEW();
    H = 0;
    N = 0;
}

link split(lin h){
    in tj;
    link t = NEW();
    for(j = 0; j < M/2; j++)
        t->b[j] h->b[M/2+j];
    h->m = M/2;
    t->m = M/2;
    return t;
}

link insertR(link h, Item item, int H){
    int i, j;
    Key v = Key(item);
    entry x;
    link t, u;
    x.key = v;
    x.ref.item = item;
    if(H == 0)
        for(j = 0; j < h->m; j++)
            if(less(v, h->b[j].key))
                break;
    if(H != 0)
        for(j = 0; j < h->m; j++)
            if(j+1 == h->m || less(v, h->b[j+1].key)){
                t = h->b[j++].ref.next;
                u = insertR(t, item, H-1);
                if(u == NULL) return NULL;
                x.key = u->b[0].key;
                x->ref.next = u;
                break;
            }

    for(i = (h->m)++; i > j; --i)
        h->b[i] = h->b[i-1];
    h->b[j] = x;
    if(h->m < M)
        return NULL;
    else return split(h);
}
void STinsert(Item item){
    link t, u = insertR(head, item, H);
    if(u == NULL)  return ;
    t = NEW(); t->m = 2;
    t->b[0].key = head->b[0].key;
    t->b[0].ref.next = head;
    t->b[1].key = u->b[0].key;
    t->b[1].ref.next = u;
    head = t;
    H++;
}
