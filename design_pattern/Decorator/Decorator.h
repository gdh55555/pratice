//Decorator.h
//
#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class Componet
{
public:
    virtual ~Componet();
    virtual void Operation();

protected:
    Componet();

};

class ConcreteComponet:public Componet
{
public:
    ConcreteComponet();
    ~ConcreteComponet();
    void Operation();
};

class Decorator:public Componet
{
public:
    Decorator(Componet* com);
    virtual ~Decorator();
    void Operation();

protected:
    Componet* _com;
};

class ConcreteDecorator:public Decorator
{
public:
    ConcreteDecorator(Componet* com);
    ~ConcreteDecorator();
    void Operation();
    void AddedBehavior();
};

#endif //~_DECORATOR_H_
