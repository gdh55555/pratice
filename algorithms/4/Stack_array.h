#include <stdlib.h>
#include "Item.h"

static int N;
static Item* s;

void STACKint(int maxN){
    s = malloc(maxN * sizeof(Item));
    N = 0;
}

int STACKempty()
{   return N == 0;}

void  STACKpush(Item item){
    s[N++] = item;
}

Item STACKpop()
{
    return s[--N];
}

