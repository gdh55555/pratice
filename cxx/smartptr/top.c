#include <iostream>

using namespace std;

class Top{
};

class Middle: public Top
{};

class Bottom: public Middle{
};

template<typename T>
class SmartPtr{
    public:
        explicit SmartPtr(T* realPtr){
        };
};

template<class T>
class SmartPtr{
    public:
        template<class U>
        SmartPtr(const SmartPtr<U>& other)
        :heldPtr(other.get()){
        }

        T* get() const{return heldPtr;}
    pivate:
        T* heldPtr;
};

int main()
{
    SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
    SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
    SmartPtr<const Top> pct2 = pt1;
}
