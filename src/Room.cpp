#include "Room.h"
#include "Aircondition.h"
//#include "Projector.h"
#include <iostream>

using namespace std;

Room::Room()
{
    //projectorDigital = NULL;
    //projectorAnalog = NULL;
    tempIndicator= new TemperatureIndicator;
    cout << "Constructor of Room class is called." << endl;
}

Room::Room (const Room &room) 
{
    aircondition = room.aircondition;
    roomType = room.roomType;
    //projectorDigital = cinemaRoom.projectorDigital;
    //projectorAnalog = cinemaRoom.projectorAnalog;
    cout << "Called coping constructor for Room." << endl;
}

Room::~Room()
{
    cout << "Destructor of Room object is called." << endl;
    delete tempIndicator;
}

    bool Room::operator== (Room const & ro1) const {
    if (ro1.roomType == roomType) { //&& ro1.aircondition == aircondition
            cout << "Saved object and read object are equal." << endl;
            return true;
          } else {
              cout << "Saved object and read object are not equal." << endl;
            return false;
          }
    }


//This method is called when movie is finished and all devices in cinema room are turn off
void Room::trunOnAircondition() {
    aircondition.setIfTurnOn(true);
    cout << "Aircondition is turn on." << endl;
}

void Room::turnOffAircondition() {
    aircondition.setIfTurnOn(false); 
    cout << "Aircondition is turn off." << endl;
}


void Room::readParamsFromConsole(){
    string yesNo;
    cout << "In this " << roomType << " is " << Room::tempIndicator->getTempValue() << " degrees Celsius. Would you like to turn on Aircondition? (write y or n)" << endl;
    do {
    cin >> yesNo;
            if (yesNo == "y" || yesNo == "n")
            {
                if (yesNo == "y") {
                aircondition.setParametersFromConsole();
                trunOnAircondition();
                Room::tempIndicator->setTempValue(aircondition.getValueOfAircondition());
                }
            } else 
            {
                cout << "It is wrong answer. Try again." << endl;
            }
        } while (yesNo != "y" && yesNo != "n");
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
    os << roomType << endl;
    os << aircondition;
}

void Room::read(istream &is) {
    //wczytaj getline room type i jesli jest pusty ( 0 length ) wczytaj jeszcze raz
    getline(is, roomType);
    if (roomType.empty()) {
        getline(is, roomType);
    }
    is >> roomType;
    is >> aircondition;

}


