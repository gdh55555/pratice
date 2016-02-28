//main.cpp
//

#include "Decorator.h"
#include <iostream>

using namespace std;

int 
main(int argc, char* argv[])
{
    Componet* com = new ConcreteComponet();
    Decorator* dec =  new ConcreteDecorator(com);

    dec->Operation();
    delete dec;
    delete com;
    return 0;
}
