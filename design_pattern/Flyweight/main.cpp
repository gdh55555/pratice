//main.cpp
//
#include "Flyweight.h"
#include "FlyweightFactory.h"
#include <iostream>

using namespace std;

int 
main(int argc, char* argv[])
{
    FlyweightFactory* fc = new FlyweightFactory();

    Flyweight* fw1 = fc->GetFlyweigh("hello");
    Flyweight* fw2 = fc->GetFlyweigh("world");

    Flyweight* fw3 = fc->GetFlyweigh("hello");
    return 0;
    
}
