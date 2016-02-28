#include <stdio.h>

char *a ; int i;

typedef struct node{
    char token;
    link l;
    link r;
}node, *link;

link NEW(char token, link l, link r){
    link x = malloc(sizeof(*x));
    x->token = token;
    x->l = l;
    x->r = r;
}

link parse()
{
    char t = a[i++];
    link x = NEW(t, NULL, NULL);
    if( t == '*' || t == '+')
    {
        x->l = parse();
        x->r = parse();
    }
    return x;
}
