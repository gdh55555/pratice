#include <iostream>
using namespace std;

struct alignas(alignof(double)*4) ColorVector{
    double r;
    double g;
    double b;
    double a;
};

template <typename T>
class FixedCapacityArray{
public:
    void push_back(T t){}

    char alignas(T) data[1024] = {0};

};

int main(){
    FixedCapacityArray<char> arrch;
    cout << "alignof(char): " << alignof(char) << endl;
    cout << "alignof(arrch.data): " << alignof(arrch.data) << endl;

    FixedCapacityArray<ColorVector> arrcv;
    cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
    cout << "alignof(arrcv.data): " << alignof(arrcv.data) << endl;

}
