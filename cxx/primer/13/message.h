#include <iostream>
#include <string>
#include <set>

using namespace std;

class Message{
    friend class Folder;
public:
    explicit Message(const string &str = "");
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();    
};
