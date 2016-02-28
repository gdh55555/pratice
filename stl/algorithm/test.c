#include <stdio.h>

int main(void)
{
    int a;
    int b = 0, c = 3;
    a = c++, b++;
    printf("%d\n", a);
    return 0;
}
