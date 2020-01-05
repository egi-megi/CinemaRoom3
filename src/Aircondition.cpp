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
    do {
    cin >> valueOfAircondition;
    cout << endl;
      if (cin.fail()) {
            valueOfAircondition=100;
            cin.clear();
            string s;
            cin>>s;
        }
    if (valueOfAircondition >= 0 && valueOfAircondition <= 50) {
        cout << "Value of temperature for aircondition is: " << valueOfAircondition << "." << endl;
    } else {
        cout << "Wrong answer. Try agin.  Value for aircondition should be between 0 and 50: " << endl;
    }
    } while (valueOfAircondition < 0 || valueOfAircondition > 50);
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
    cout<<"read valueOfAircondition =="<<ar.valueOfAircondition<<"\n";
    is >> ar.ifTurnOn;
    is >> ar.heat;
    is >> ar.cool;
    return is;
}




