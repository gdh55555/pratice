#include <iostream>
#include "stl_function.h"

using namespace std;

int main(int argc, const char *argv[])
{
    equal_to<int> equal_to_obj;
    not_equal_to<int> not_equal_to_obj;
    greater<int> greater_obj;
    less<int> less_obj;
    less_equal<int> less_equal_obj;

    cout << equal_to_obj(3, 6) << endl;
    cout << not_equal_to_obj(3, 5) << endl;
    cout << greater_obj(3, 5) << endl;
    cout << less_obj(3, 6) << endl;
    cout << less_equal_obj(4, 4) << endl;


    cout << equal_to<int>()(3, 5) << endl;
    return 0;
}
