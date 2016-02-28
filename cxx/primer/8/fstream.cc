#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vstring;
    string file("111.txt");
    ifstream in(file);
    string line;

    while(/*getline(in, line)*/ !in.eof() ){
        string tmp;
        in >> tmp;
        vstring.push_back(tmp);
        cout << tmp << endl;
    }

    vector<string>::iterator it = vstring.begin();
    while(it != vstring.end())
    {
        cout << *it++ << endl;
    }
    return 0;
}
