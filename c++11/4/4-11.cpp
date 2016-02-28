#include <iostream>
using namespace std;

int x;
int * y = &x;
double foo();
int& bar();

auto* a = &x;
auto* b = x;
auto c = y;
auto* d = y;
auto* e = &foo(); //编译失败，指针不能指向一个临时变量
auto& f = foo();  //同理的问题
auto g = bar();
auto& h = bar();

