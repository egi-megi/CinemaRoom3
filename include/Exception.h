#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

using namespace std;

class Exception
{
 public:
        virtual const char* description()const=0;
        virtual ~Exception(){}
};

#endif // EXCEPTION_H