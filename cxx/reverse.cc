#include <iostream>
#include <string>

using namespace std;
void reverseWords(string&);

int main(int argc, const char *argv[])
{
    string s = "  a       b ";
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
    return 0;
}
void reverseWords(string &s) {
    if(s.size() == 0)
        return;
    int i = 0;
    int j = s.size() -1;
    while(j > i && s[j] == ' ')
        j--;
    while(j > i && s[i] == ' ')
        i++;
    bool flagi = false, flagj = false;
    while(i < j){
        if(flagi && s[i] == ' '){
            i++;
            continue;
        }
        if(flagj && s[j] == ' '){
            j--;
            continue;
        }
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
        flagi = flagj = false;
        if(s[i-1] == ' ')
            flagi = true;
        if(s[j+1] == ' ')
            flagj = true;
    }

}
