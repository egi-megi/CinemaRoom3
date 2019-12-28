#ifndef AIRCONDITION_H
#define AIRCONDITION_H
#include "TemperatureIndicator.h"
#include <iostream>

using namespace std;

class Aircondition
{
    public:
        Aircondition();
        Aircondition (const Aircondition &aircondition);
        ~Aircondition();
        
        //TemperatureIndicator *tempIndicator ;

        void operator++(int);
        void operator--(int);
        bool operator==(Aircondition const & ar1) const;

        //void check(int tempInCinemaRoom);
        int getValueOfAircondition();
        void setValueOfAircondition();
        void setIfTurnOn (bool ifT);
        bool getIfTurnOn();
        void setParametersFromConsole();
        friend ostream & operator<<(ostream & os, const Aircondition & a);
        friend istream & operator>>(istream & is, Aircondition & ar);
        

    protected:
    private:
    int valueOfAircondition;
    bool ifTurnOn;
    bool heat;
    bool cool;
};

#endif
