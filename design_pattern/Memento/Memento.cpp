// Memento.cpp
//
#include "Memento.h"
#include <iostream>
using namespace std;
typedef string State;
Originator::Originator()
{
    _sdt = "";
    _mt =0;
}

Originator::Originator(const State& sdt)
{
    _sdt = sdt;
    _mt = 0;
}

Originator::~Originator()
{}

Memento* Originator::CreateMemento()
{
    return new Memento(_sdt);
}

State Originator::GetState()
{
    return _sdt;
}

void Originator::SetState(const State& sdt)
{   
    _sdt = sdt;
}

void Originator::PrintState()
{
    cout << this->_sdt << "..." << endl;
}

void Originator::SetMemento(Memento* mem)
{}

void Originator::RestoreMemento(Memento* mem){
    this->_sdt = mem->GetState();
}

Memento::Memento()
{}

Memento::~Memento()
{}

Memento::Memento(const State& sdt)
{
    _sdt = sdt;
}

State Memento::GetState()
{
    return _sdt;
}

void Memento::SetState(const State& sdt)
{
    _sdt = sdt;
}



