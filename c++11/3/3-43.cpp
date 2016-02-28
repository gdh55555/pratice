#include <iostream>
#include <cstring>

using namespace std;

struct Student{
    Student(bool g, int s): gender(g), age(s){}
    bool gender;
    int age;
};

class Singer{
    public:
        enum Type {STUDENT, NATIVE, FOREIGNER};

        Singer(bool g, int a): s(g, a){t = STUDENT;}
        Singer(int i):id(i){t = NATIVE;}
        Singer(const char* n, int s){
            int size = (s>9) ? 9 : s;
            memcpy(name ,n, size);
            name[s] = '\0';
            t = FOREIGNER;
        }

        ~Singer(){}

    private:
        Type t;
        union{
            Student s;
            int id;
            char name[10];
        };
};

int main(){
    Singer(true, 13);
    Singer(32323);
    Singer("JFA E FA", 9);
}
