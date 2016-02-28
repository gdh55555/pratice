#include <stdio.h>

int count(link t)
{
    if(t == NULL)
        return 0;
    return 1+count(t->next);
}

void traverse(link k, void (*visit)(link)){
    if(k == NULL)
        return ;
    (*visit)(h);
    traverse(h->next, visit);
}

void traverseR(link k, void (*visit)(link)){
    if(k == NULL)
        return ;
    traverseR(k->next, visit);
    (*visit)(k);
}
link delete(link k, Item i){
    if(k == NULL) return ;
    if(eq(k->item, i)){
        link c = k->next;
        free(k);
        return c;
    }
    k->next = delete(k->next, i);
    return k;
}
