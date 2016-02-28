#include <stdlib.h>

typedef STnode* link;
struct STnode{Item item; link l,r; };

link rotR(link h){
    link x = h->l;
    h->l = x->r;
    x->r = h;
    return x;
}

link rotL(link h){
    link x = h->r;
    h->r = x->l;
    x->l = h;
    return x;
}

link insert(link h, Item item){
    Key v = key(item);
    if(h == z)
        return NEW(item, z, z, 1);
    if(less(v, key(h->item))){
        h->l = insert(h->l); h = rotR(h);
    }else{
        h->r = insert(h->r, item);
        h = rotL(h);

    }
    return h;
}
