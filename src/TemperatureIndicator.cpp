#include "TemperatureIndicator.h"
#include <iostream>

using namespace std;

TemperatureIndicator::TemperatureIndicator()
{
    tempValue = 5;
    cout << "Constructor of TemperatureIndicator class is called." << endl;
}

TemperatureIndicator::~TemperatureIndicator()
{
    cout << "Destructor of TemperatureIndicator object is called." << endl;
}
void TemperatureIndicator::setTempValue(int t)
{
TemperatureIndicator::tempValue = t;
}

int TemperatureIndicator::getTempValue() {
   // cout << "Temperature in cinema room is: " << TemperatureIndicator::tempValue << " degree." << endl; 
  return TemperatureIndicator::tempValue;
}

ostream & operator<<(ostream & os, const TemperatureIndicator & t) {
    os << t.tempValue << endl;
    return os;
}

istream & operator>>(istream &is, TemperatureIndicator & ti) {
    is >> ti.tempValue;
    return is;
}
