#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 1;
    uint32_t tmp;
    for(int i = 0; i < 32; i++){
        tmp = (n & 0x01) | 0xFFFFFFFE;
        cout << i << " " << tmp << endl;
        n >> 1;
        res = (res << 1) & tmp;
        cout << res << endl;
    }
    return res;
}

int main(){
    uint32_t n;
    cin >> n;
    cout << reverseBits(n) << endl;
}
