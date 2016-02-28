#include <stdio.h>

int count(link h){
    if(h == NULL)
        return 0;
    return count(h->left) + count(h->right) + 1;
}

int height(link h){
    if(h == NULL)
        return -1;
    int l = height(h->left);
    int r = height(h->right);
    return (l > r) ? l+1 : r+1;
}
