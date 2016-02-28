//Decorator.cpp
//
#include "Decorator.h"
#include <iostream>

using namespace std;

Componet::Componet()
{
}

Componet::~Componet()
{
}

void Componet::Operation()
{
}

ConcreteComponet::ConcreteComponet()
{}

ConcreteComponet::~ConcreteComponet()
{}

void ConcreteComponet::Operation()
{
    cout << "ConcreteComponet Operation" << endl;
}

Decorator::Decorator(Componet* com)
{
    this->_com = com;
}

Decorator::~Decorator()
{
}

void Decorator::Operation()
{}

ConcreteDecorator::ConcreteDecorator(Componet* com):Decorator(com)
{}

ConcreteDecorator::~ConcreteDecorator()
{}

void ConcreteDecorator::AddedBehavior()
{
    cout << "ConcreteDecorator::AddedBehavior"<< endl;
}

void ConcreteDecorator::Operation()
{
    _com->Operation();
    this->AddedBehavior();
}


