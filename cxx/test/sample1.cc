#include <iostream>
using namespace std;

int is_leap_year(int n){
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return 1;
    else
        return 0;
}

int judge(){
    int months[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                      {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int day, month, year;
    cin >> day >> month >> year;
    if(month > 0 && month < 13){
        if(day >= 1 && day <= months[is_leap_year(year)][month])
            return 1;
    }
    return 0;
}

int main(){
    if(judge())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
