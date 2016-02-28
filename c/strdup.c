#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "strdup";
    char *b;
    char *c="hello,world";
    //b = strdup(a);
    //b = malloc(10 * sizeof(*b));
    //strcpy(b,a);
    b = c;
    printf("b[] = \" %s \" \n",b);
    return 0;
}
