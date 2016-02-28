//Invoker.h
//
#ifndef _INVOKER_H_
#define _INVOKER_H_

class Command;

class Invoker
{
    public:
        Invoker(Command* cmd);
        ~Invoker();
        void Invoker();
    private:
        Command* _cmd;
};

#endif //~_INVOKER_H_
