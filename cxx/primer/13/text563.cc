#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int i, j;

    while(cin >> i >> j)
    {
        try{
            if (0 == j)
                throw runtime_error("can not to 0");
            cout << i /j << endl;
        }catch(runtime_error err){
            cout << err.what()
                << "\n Try Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if(!cin || c == 'n')
                break;
        }
    }
    return 0;
}
