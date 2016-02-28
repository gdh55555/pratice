#include <iostream>
using namespace std;

struct A{
    A(){}
    A(const A&& a){ cout << "Copy Constructed" << __func__ << endl;}
    A(A&& a){ cout << "Move Constructed" << __func__ << endl;}
};
struct B{
    B(){}
    B(const A&& a){ cout << "Copy Constructed" << __func__ << endl;}
    B(A&& a){ cout << "Move Constructed" << __func__ << endl;}
};

template<typename... T> struct MultiType;
template<typename T1, typename... T>
struct MultiType<T1, T...> : public MultiType<T...>{
    T1 t1;
    MultiType<T1, T...>(T1 a, T...b) : t1(a), MultiType<T...>(b...){
        cout << "MultiType<T1, T... b" << endl;
    }
};

template<> struct MultiType<>{
    MultiType<>(){ cout << "MultiType<>()" << endl;}
}
;

template<template <typename...> class VariadicType, typename... Args>
VariadicType<Args...> Build(Args&&... args){
    return VariadicType<Args...>(std::forward<Args>(args)...);
}

int main(){
    A a;
    B b;

    Build<MultiType>(a, b);
}
