#include <iostream>
#include <queue>

using namespace std;

struct A{
    int a;
};
int main(){
    queue<struct A*> q;
    q.push(NULL);
    struct A* a;
    a = q.front();
    q.pop();
    cout << 111<<endl;

}
