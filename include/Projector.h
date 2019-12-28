#ifndef PROJECTOR_H
#define PROJECTOR_H
#include <iostream>

using namespace std;

class Projector
{
    public:
        Projector(string projType);
        virtual ~Projector();
        string getProjectorType();
        void turnOn();
        void turnOff();

        friend ostream & operator<<(ostream & os, const Projector & p);
        friend istream & operator>>(istream & is, Projector & pr);
    
    protected:
    private:
    bool isTurnOn;
    string projectorType;
};

#endif // PROJECTOR_H
