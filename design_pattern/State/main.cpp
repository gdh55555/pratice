//main.cpp
//
#include "State.h"
#include "Context.h"
#include <iostream>
using namespace std;

int 
main(int argc, char* argv[])
{
    State* st = new ConcreteStateA();
    Context* con = new Context(st);
    con->OperationInterface();
    con->OperationChangeState();
    con->OperationInterface();
    delete con;
    delete st;
    return 0;
}
