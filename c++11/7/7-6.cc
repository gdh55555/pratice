#include <iostream>
#include <cstddef>
using namespace std;

int main(){
    nullptr_t mynull;
    printf("%x\n", &mynull);

    printf("%d\n", mynull == nullptr);

    const nullptr_t&& default_nullptr = nullptr;

    printf("%x\n", &default_nullptr);
}
