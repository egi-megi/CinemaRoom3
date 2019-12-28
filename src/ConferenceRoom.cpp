#include "ConferenceRoom.h"
#include "Room.h"
#include "Aircondition.h"
#include "Projector.h"
#include "Screen.h"
#include <iostream>

using namespace std;

ConferenceRoom::ConferenceRoom()
{
    projectorDigital = NULL;
    areWindowsOpen = false;
    cout << "Constructor of ConferenceRoom class is called." << endl;
}

ConferenceRoom::ConferenceRoom (const ConferenceRoom &conferenceRoom) 
{
    //aircondition = conferenceRoom.aircondition;
    projectorDigital = conferenceRoom.projectorDigital;
    screen = conferenceRoom.screen;
    cout << "Called coping constructor for ConferenceRoom." << endl;
}

ConferenceRoom::~ConferenceRoom()
{
    cout << "Destructor of ConferenceRoom object is called." << endl;
}

void ConferenceRoom::openWindows() {
    if (areWindowsOpen == false) {
        cout << "Windows have been closed, so they will be open in a moment." << endl;
        areWindowsOpen = true;
    } else {
        cout << "Windows have been opened." << endl;
    }
}

string ConferenceRoom::getRoomTypeName(){
    return "Conference Room";
}

void ConferenceRoom::closeWindows() {
    if (areWindowsOpen == false) {
        cout << "Windows have been closed." << endl;
    } else {
        cout << "Windows have been opened, so they will be closed in a moment." << endl;
        areWindowsOpen = false;
    }
}

void ConferenceRoom::closeAllInRoom() {
    if (projectorDigital!=NULL) {
        projectorDigital->turnOff();
    }
    //turnOffAircondition(); 
    closeWindows();
}

void ConferenceRoom::readParamsFromConsole() {
    Room::readParamsFromConsole();
    screen.readHeightOfScreenFromConsole();
    readOpenCloseWindowsFromConsole();
}

void ConferenceRoom::readOpenCloseWindowsFromConsole() {
    string yesNo;
    if (areWindowsOpen) {
        cout << "Windows are opened. Do you want to close them? (Write y or n)" << endl;
        cin >> yesNo;
        cout << endl;
        if (yesNo == "y") {
            closeWindows();
        }
    } else {
        cout << " Windows are closed. Do you want to open it? (Write y or n)" << endl;
        cin >> yesNo;
        cout << endl;
        if (yesNo == "y") {
            openWindows();
        }
    }
}

// Method for getting new projector in cinema room
void ConferenceRoom::operator+= (Projector* proj) {
            if (projectorDigital == NULL) { 
                projectorDigital = proj;
                 cout << "There is " << projectorDigital->getProjectorType() << " projector set in this cinema room." << endl;
               } else {
                   cout << "Cinema room has already " << projectorDigital->getProjectorType() << " projector." << endl;
               }
        }
        

// Method used for example when projector is borken and must be removed
/*void ConferenceRoom::operator-= (Projector* projDel) {
        if (projDel != NULL) { 
            cout << "Projector " << projectorDigital->getProjectorType() << " was removed." << endl;
            projDel = NULL;
        } else {
            cout << "Cinema room has no" << projectorDigital->getProjectorType() << " projector." << endl;
        }
}*/

    bool ConferenceRoom::operator== (ConferenceRoom const & cro1) const {
       if (Room::operator==(cro1) /* && co tam jeszce chce*/) {
            cout << "Saved object and read object are equal." << endl;
            return true;
          } else {
              cout << "Saved objcet and read object are not equal." << endl;
            return false;
          }
    }