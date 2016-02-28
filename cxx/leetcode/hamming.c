#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    const uint32_t m1 = 0x55555555;
    const uint32_t m2 = 0x33333333;
    const uint32_t m3 = 0x0f0f0f0f;
    const uint32_t m4 = 0x00ff00ff;
    const uint32_t m5 = 0x0000ffff;
    const uint32_t m6 = 0xffffffff;
    n = (n & m1) + (n >> 1 & m1);
    n = (n & m2) + (n >> 2 & m2);
    n = (n & m3) + (n >> 4 & m3);
    n = (n & m4) + (n >> 8 & m4);
    n = (n & m5) + (n >> 16 & m5);
    return n;
}

int main()
{
    printf("%d\n", hammingWeight(11));
}
