#ifndef OFEXCEPTION_H
#define OFEXCEPTION_H
#include "Exception.h"
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

    class OpeningFileException : public Exception{
        char* statement;
        public:
        OpeningFileException(const char*name){
            const char*format="Problem with opening file %s";
            statement =new char[strlen(format)+strlen(name)-1];
            sprintf(statement,format,name);
        }
        const char* description()const{
            return statement;
        }
        ~OpeningFileException(){
            delete[]statement;
        }
        };

#endif // OFEXCEPTION_H
