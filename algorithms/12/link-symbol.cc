typedef struct STnode* link;
struct STnode{
    Item item;
    link next;
};

static link head, z;
static int N;
static link NEW(Item item, link next){
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

void STinit(int max){
    N = 0;
    head = (z = NEW(NULLItem, NULL));
}

int STcount(){
    return N;
}

Item search(link t, Key v){
    if(t == z) return NULLItem;
    if(eq(key(t->item), v)) return t->item;
    return search(t->next, v);
}

void STinsert(Item item){
    head = NEW(item, head);
    N++;
}
