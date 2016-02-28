#include <stdio.h>

void GetNext(char* p, int next[]){
    int plen = strlen(p);
    int j = 0;
    int k = -1;
    next[0] = -1;
    while(j < plen){
        if(k == -1 || p[k] == p[j]){
            ++k;
            ++j;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}

void GetNext(char* p, int next[]){
    int plen = strlen(p);
    int j = 0;
    int k = -1;
    next[0] = -1;
    while(j < plen){
        if(k == -1 || p[k] == p[j]){
            ++k;
            ++j;
            if(p[k] != p[j])
                next[j] = k;
            else
                next[j] = next[k];
        }else{
            k = next[k];
        }
    }
}
