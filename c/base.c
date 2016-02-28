#include <iostream>
using namespace std;

class base{
    public:
        base(){
            cout << "Base:.. " << endl;
        }

        virtual void print(){
            cout << "HELLO Base.." << endl;
        }
};

class dirived:public base {
    public:
        dirived(){
            cout << "Dirived:..." << endl;
        }

        virtual void print(){
            cout << "World Dirived..." << endl;
        }
};

int main()
{
    base* pb = new base();
    base* pd = new dirived();
    pb->print();
    pd->print();
    cout << "--------------------------" << endl;
    dirived* pdd = new dirived();
    pdd->print();
    return 0;
}
