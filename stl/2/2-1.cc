#include <iostream>
using namespace std;

char* strchr(char* s, int c){
    while(*s != '\0' && *s != c)
        ++s;
    return *s == c ? s : (char*)0;
}

char find1(char* first, char* last, int c){
    while(first != last && *first != c)
        first++;
    return first;
}

template <class T>
T* find2(T* first, T* last, T value);

template<class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& value){
    while(first != last && *first != c)
        first++;
    return first;
}

template <class Node>
struct node_wrap{
    Node* ptr;

    node_wrap(Node* p = 0) : ptr(0) {}
    Node& operator*() const {return *ptr;}
    Node* operator->() const {return ptr;}

    node_wrap& operator++() {ptr = ptr->next; return *this}
    node_wrap operator++(int) {node_wrap tmp = *this; ++*this; return tmp;}

    bool operator==(const node_wrap& i) const {return ptr == i.ptr;}
    bool operator!=(const node_wrap& i) const {return ptr != i.ptr;}
};
