#include <stdlib.h>
#include "Item.h"

typedef struct QUEUEnode* link;

struct QUEUEnode{
    Item item;
    link next;
};

static link tail, head;
 
link NEW(Item item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

void QUEUEinit(int maxN)
{
    head = NULL;
}

int QUEUEempty(){
    return head == NULL;
}

void QUEUEput(Item item)
{
    if(head == NULL){
        head = NEW(item, head);
        tail = head;
        return;
    }
    tail->next = NEW(item, tail->next);
    tail = tail->next;
}

Item QUEUEget()
{
    Item item = head->item;
    link x = head->next;
    free(head);
    head = x;
    return item;
}
