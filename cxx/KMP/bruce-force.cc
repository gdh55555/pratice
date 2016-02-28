#include <stdio.h>

int voilentMatch(char* s, char *p){
    int lens = strlen(s);
    int lenp = strlen(p);

    int i = 0;
    int j = 0;
    while(i < lens && j < lenp){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            i = i-(j-1);
            j = 0;
        }
    }
    if(j == lenp)
        return i-j;
    else 
        return -1;
}
