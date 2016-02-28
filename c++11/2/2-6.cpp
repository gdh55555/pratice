#include <cassert>
#include <cstdlib>
#ifdef NDEBUG
#define assert(expr) (static_cast<void> (0))
#else

#endif 
using namespace std;

char* ArrayAlloc(int n){
    assert(n > 0);
    return (char*)malloc(sizeof (char) * n);
}

int main(){
    char* a = ArrayAlloc(0);
}
