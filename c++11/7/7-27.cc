#include <iostream>
using namespace std;

int main(){
    int val;

    auto const_val_lambda = [=](){val = 3;} //不能修改常量
    auto mutable_val_lambda = [=] ()mutable {val = 3;}

    auto const_ref_lambda = [&] {val = 3;} //没有改动引用本身

    auto const_param_lambda = [&](int v) {v = 3;}
    const_param_lambda(val);//通过传递参数

    return 0;
}
