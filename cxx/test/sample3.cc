#include <iostream>
#include <stdio.h>
using namespace std;

double cross_product(double x1, double y1, double x2, double y2,
        double x3, double y3)
{
    return (x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1);
}

int main()
{
    double pt[8];
    for(int i=0;i<8;i++)
        scanf("%d", &pt[i]);
    double cp1 = cross_product(x1, y1, x2, y2, x, y);
    double cp2 = cross_product(x2, y2, x3, y3, x, y);
    double cp3 = cross_product(x3, y3, x1, y1, x, y);
    if(cp1 < 0 && cp2 < 0 && cp3 < 0 ||cp1 > 0 && cp2 > 0 && cp3 > 0)
        printf("In");
    if(cp1 == 0 || cp2 == 0 || cp3 == 0)
        printf("on");
    printf("out");
    return 0;
}

string  ptTra(double x1, double y1, double x2, double y2,
        double x3, double y3, double x,  double y)
{
    double cp1 = cross_product(x1, y1, x2, y2, x, y);
    double cp2 = cross_product(x2, y2, x3, y3, x, y);
    double cp3 = cross_product(x3, y3, x1, y1, x, y);
    if(cp1 < 0 && cp2 < 0 && cp3 < 0 ||cp1 > 0 && cp2 > 0 && cp3 > 0)
        return "In";
    if(cp1 == 0 || cp2 == 0 || cp3 == 0)
        return "on";
    return "out";

}


