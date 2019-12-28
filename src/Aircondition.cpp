#include "Aircondition.h"
#include "Movie.h"
#include "TemperatureIndicator.h"
#include <iostream>

using namespace std;

Aircondition::Aircondition()
{
valueOfAircondition = 20;
ifTurnOn = false;
//tempIndicator= new TemperatureIndicator;
cout << "Constructor of Aircondition class is called." << endl;
}

Aircondition::Aircondition (const Aircondition &aircondition) 
{
    valueOfAircondition = aircondition.valueOfAircondition;
    ifTurnOn = aircondition.ifTurnOn;
    //tempIndicator= aircondition.tempIndicator;
    heat = aircondition.heat;
    cool = aircondition.cool;
    cout << "Called coping constructor for Aircondition." << endl;
}

Aircondition::~Aircondition()
{
    cout << "Destructor of Aircondition object is called." << endl;
    //delete tempIndicator;
}

int Aircondition::getValueOfAircondition() {
    cout << "Value of temperature for aircondition is: " << valueOfAircondition << "." << endl;
    return valueOfAircondition;
}

void Aircondition::operator++ (int){
    valueOfAircondition++;
}

void Aircondition::operator-- (int){
    valueOfAircondition--;
}

bool Aircondition::operator==(Aircondition const & ar1) const{
    if (ar1.valueOfAircondition == valueOfAircondition &&
      ar1.ifTurnOn == ifTurnOn &&
        ar1.heat == heat &&
          ar1.cool == cool) {
              cout << "Saved object and read object are equal." << endl;
            return true;
          } else {
              cout << "Saved objcet and read object are not equal." << endl;
            return false;
          }
          
}

void Aircondition::setValueOfAircondition(){
    cout << "What temperature shoud be set on aircondition: ";
    cin >> valueOfAircondition;
    cout << endl;
    /*if (valueOfAircondition < va) {
        int i = va - valueOfAircondition;
        while(i > 0) {
            (*this)++ ;
          i--;
        }
    } else if (valueOfAircondition > va) {
        int j = valueOfAircondition - va;
        while(j > 0) {
          (*this)--;
          j--;
        }
    } else {
    
    }
    //check(int tempInCinemaRoom);
    cout << "Temperature value for aircondition will changed to: " << va << endl;*/
}

void Aircondition::setIfTurnOn(bool ifT) {
ifTurnOn = ifT;
}

bool Aircondition::getIfTurnOn() {
    return ifTurnOn;
}

void Aircondition::setParametersFromConsole() {
    setValueOfAircondition();
}

ostream & operator<<(ostream & os, const Aircondition & a) {
    os << a.valueOfAircondition<<endl;
    os << a.ifTurnOn<<endl;
    os << a.heat<<endl;
    os << a.cool<<endl;
    return os;
}

istream & operator>>(istream &is, Aircondition & ar) {
    is >> ar.valueOfAircondition;
    is >> ar.ifTurnOn;
    is >> ar.heat;
    is >> ar.cool;
    return is;
}

/*
void Aircondition::turnOn(){
   ifTurnOn=true;
   cout << "Aircondition is turn on." << endl;
}

void Aircondition::turnOff(){
    ifTurnOn=false; 
    cout << "Aircondition is turn off." << endl;
}*/

/*
void Aircondition::check(int tempInCinemaRoom){
    if (! ifTurnOn){
        cool=false;
        heat=false;
        cout << "Aircondition is off"<<endl;
        return;
    }
    if ((tempInCinemaRoom < valueOfAircondition + 2) && (tempInCinemaRoom > valueOfAircondition - 2 ) ) {
        cool=false;
        heat=false;
        cout << "Temperature in cinema room is: " << tempInCinemaRoom << " degree. It is ok. Aircondition will be stand by." << endl;
         
    } */

        /*if (tempIndicator->getTempValue() <= valueOfAircondition - 2 ) {
        cool=false;
        heat=true;
        cout << "Temperature in cinema room is: "<< tempIndicator->getTempValue() << " degree. It is too cold. Aircondition will heat."<<endl;
    }*/
    /*if (tempInCinemaRoom <= valueOfAircondition - 2 ) {
        cool=false;
        heat=true;
        cout << "Temperature in cinema room is: "<< tempInCinemaRoom << " degree. It is too cold. Aircondition will heat."<<endl;
    }
    
    if (tempInCinemaRoom >= valueOfAircondition + 2 ) {
        cool=true;
        heat=false;
        cout << "Temperature in cinema room is: " << tempInCinemaRoom << " degree. It is too warm. Aircondition will cool."<<endl;
    }
}*/


