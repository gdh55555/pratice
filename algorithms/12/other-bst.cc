
Item selectR(link h, int k){
    int t;
    if(h == z) 
        return NULLitem;
    t = (h->l == z) ? 0 : h->l->N;
    if(t > k)   return selectR(h->l, k);
    if(t < k) return selectR(h->r, k-t-1);
    return h->item;
}

link partR(link h, int k){
    int t = h->l->N;
    if(t > k){
        h->l = partR(h->l, k);
        h = rotR(h);
    }
    if(t < k){
        h->r = partR(h->r, k-t-1);
        h = rotL(h);
    }
    return h;
}

link joinLR(link a, link b){
    if(b == z) return a;
    b = partR(b, 0);
    b->l = a;
    return b;
}

link deleteR(link h, Key v){
    link x;
    Key t = Key(h->item);
    if(h == z) return z;
    if(less(v, t))  h->l = deleteR(h-l, v);
    if(less(t, v)) h->r = deleteR(h->r, v);
    if(eq(v,t)){
        x = h;
        h = joinLR(h->l, h->r);
        free(x);
    }
    return h;
}

link STjoin(link a, link b){
    if(b == z)  return a;
    if(a == z) return b;
    b = insertT(b, a->item);
    b->l = STjoin(a->l, b->l);
    b->r = STjoin(a->r, b->r);
    free(a);
    return b;
}
