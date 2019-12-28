#include "Room.h"
#include "Aircondition.h"
//#include "Projector.h"
#include <iostream>

using namespace std;

Room::Room()
{
    //projectorDigital = NULL;
    //projectorAnalog = NULL;
    chairNumber = 0;
    tempIndicator= new TemperatureIndicator;
    cout << "Constructor of Room class is called." << endl;
}

Room::Room (const Room &room) 
{
    //aircondition = room.aircondition;
    chairNumber = room.chairNumber;
    //projectorDigital = cinemaRoom.projectorDigital;
    //projectorAnalog = cinemaRoom.projectorAnalog;
    cout << "Called coping constructor for Room." << endl;
}

Room::~Room()
{
    cout << "Destructor of Room object is called." << endl;
    delete tempIndicator;
}

void Room::checkTemperature(){
    cout << "Temperature in this room is " << tempIndicator->getTempValue() << "."<<"\n";
    /*string yesNo ;
    if (aircondition.getIfTurnOn() == false) {
        cout << "Aircondition is turn off. Would you like to turn on it? (Write yes/no)"<<"\n";
        cin >> yesNo;
        if (yesNo == "yes") {
            trunOnAircondition();
        }
    } else {
        cout << "Aircondition is turn on. Would you like to turn off it? (Write yes/no)"<<"\n";
        cin >> yesNo;
        if (yesNo == "yes") {
            turnOffAircondition();
        }
    }*/
}

    bool Room::operator== (Room const & ro1) const {
    if (ro1.chairNumber== chairNumber ) { //&& ro1.aircondition == aircondition
            cout << "Saved object and read object are equal." << endl;
            return true;
          } else {
              cout << "Saved objcet and read object are not equal." << endl;
            return false;
          }
    }


//This method is called when movie is finished and all devices in cinema room are turn off
/*void Room::trunOnAircondition() {
    aircondition.setIfTurnOn(true);
   cout << "Aircondition is turn on." << endl;
}

void Room::turnOffAircondition() {
    aircondition.setIfTurnOn(false); 
    cout << "Aircondition is turn off." << endl;
}*/


void Room::readParamsFromConsole(){
    setNumberOfChairs();
    //aircondition.setParametersFromConsole();
}

void Room::setNumberOfChairs() {
    cout << "Write how many chairs should be in: ";
    cin >> chairNumber;
    cout << endl;
}
int Room::getNumberOfChairs() {
    cout << "In the room will be " << chairNumber << "." << endl;
    return chairNumber;
}

ostream & operator<<(ostream & os, const Room & r) {
    r.write(os);
    return os;
}

istream & operator>>(istream &is, Room & ro) {
    ro.read(is);
    return is;
}

void Room::write(ostream & os) const{
    os << chairNumber<<endl;
    //os << aircondition;
}

void Room::read(istream &is) {
    is >> chairNumber;
    //is >> aircondition;
}


