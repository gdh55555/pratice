#include <stdio.h>
#include <unistd.h>
#include "attribute.h"
__attribute__((constructor))
void init()
{
    printf("init \n");
}

int attribute()
{
    printf("in attribute \n");
    return 0;
}
