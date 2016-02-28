#include <stdio.h>

int f()
{
    printf("f( ) \n");
reboot:
    printf("reboot \n");

}

int main()
{
    printf("in main() \n");
    f();
    printf("end \n");
    return 0;
}
