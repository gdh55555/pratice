#include <iostream>
using namespace std;

template<typename T>
void doProcessing(T& w)
{
    cout << "Hello..." << endl;
}

class Base{
    public:
        Base(){
            cout << "Base..." << endl;
        }

};

int main()
{
    Base w;
    doProcessing(w);
}
