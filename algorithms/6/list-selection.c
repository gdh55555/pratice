#include <stdio.h>
#include <stdlib.h>

link listselection(link h){
    link max, t, out = NULL;
    while(h->next != NULL){
        max = findiMax(h);
        t=max->next;
        max->next = t->next;
        t->next = out;
        out=t;
    }
    h->next = out;
    return h;
}
