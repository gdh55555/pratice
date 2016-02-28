#include <stdio.h>

void traverse(link h, void (*visit)(link))
{
    stack<int> s;
    s.push(h);
    while(!h.empty()){
        visit(h = s.pop());
        if(h->r != NULL) h.push(h->r);
        if(h->l != NULL) h.push(h->l);
    }
}
