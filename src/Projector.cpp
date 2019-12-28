#include "Projector.h"

Projector::Projector(string proType)
{
    projectorType = proType;
    isTurnOn = false;
    cout << "Constructor of Projector class is called." << endl;
}

Projector::~Projector()
{
    cout << "Destructor of Projector object is called." << endl;
}

string Projector::getProjectorType() 
{
//cout << "This cinema room has " << projectorType << " projector." << endl; 
  return projectorType;
}

void Projector::turnOn(){
   isTurnOn=true;
   cout << "Projector is turn on." << endl;
}

void Projector::turnOff(){
    isTurnOn=false; 
    cout << "Projector is turn on." << endl;
}

ostream & operator<<(ostream & os, const Projector & p) {
    os << p.isTurnOn << endl;
    os << p.projectorType << endl;
    return os;
}

istream & operator>>(istream &is, Projector & pr) {
    is >> pr.isTurnOn;
    is >> pr.projectorType;
    return is;
}
