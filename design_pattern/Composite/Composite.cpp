//Composite.cpp
//
#include "Composite.h"

#define NULL 0
Composite::Composite()
{
    vector<Component*>::iterator itend = comVec.begin();
}

Composite::~Composite()
{}

void Composite::Operation()
{
    
    vector<Component*>::iterator comIter = comVec.begin();
    for(;comIter!= comVec.end(); comIter++)
        (*comIter)->Operation();
}

void Composite::Add(Component* com)
{
    comVec.push_back(com);
}

void Composite::Remove(Component* com)
{
 //   comVec.erase(&com);
}

Component* Composite::GetChild(int index)
{
    return comVec[index];
}


