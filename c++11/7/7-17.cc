#include <iostream>
using namespace std;

int main(){
    int grils = 3, boy = 4;
    auto totalChild = [](int x, int y)->int {return x + y;};
    cout <<  totalChild(grils, boy) << endl;
}
