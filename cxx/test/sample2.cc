#include <stdio.h>
int main(){
    int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);
    if(month > 0 && month < 13){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            months[2] = 29;
        if(day >= 1 && day <= months[month])
            printf("YES\n");
    }
    printf("NO\n");

}
