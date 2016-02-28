#include <stdio.h>

void traverse(int k , void (*visit)(int)){
    link t;
    static queue q;
    q.push(k);
    while(!q.empty()){
        k = q.front();
        q.pop();
        if(visited[k] == 0){
            visit(k);
            visited[k] = 1;
            for(t = adj[k]; t != NULL; t=t->next)
                if(!visited[t->v])
                    q.push(t->v);
        }
    }
}
