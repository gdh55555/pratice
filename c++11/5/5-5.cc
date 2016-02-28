#include <iostream>
using namespace std;

enum class Type {General, Light, Medium, Heavy};
enum class Category {General = 1, Pistol, MachineGun, Cannon};

int main(){
    Type t = Type::Ligth;

    //t = General  //编译失败，必须使用强类型名称
    if(t == Category::General){
        cout << "General Weapon" << endl;
    }
    if(t > Type::General)
        cout << "Not General Weapon" << endl;
    if(t > 0)
        cout <<"Not General Weapon" << endl;
    if((int)t > 0)
        cout <<"Not General Weapon" << endl;
    cout << is_pod<Type>::value << endl;
    cout << is_pod<Category>::value << endl;
        
}
