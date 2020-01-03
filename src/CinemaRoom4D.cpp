#include "CinemaRoom4D.h"
#include "CinemaRoom.h"
#include "Room.h"
#include "Aircondition.h"
#include "Projector.h"
#include "Screen.h"
#include "Sound.h"
#include "Movie.h"
#include <iostream>

using namespace std;

CinemaRoom4D::CinemaRoom4D() :CinemaRoom()
{
    roomType = "Cinema Room 4D";
    isArmchairOn = false;
    cout << "Constructor of CinemaRoom class is called." << endl;
}

CinemaRoom4D::CinemaRoom4D (const CinemaRoom4D &cinemaRoom4D)  :CinemaRoom(cinemaRoom4D)
{

    isArmchairOn = cinemaRoom4D.isArmchairOn;
    cout << "Called coping constructor for CinemaRoom4D." << endl;
}

CinemaRoom4D::~CinemaRoom4D()
{
    cout << "Destructor of CinemaRoom4D object is called." << endl;
 
}

void CinemaRoom4D::playMovie(Movie * movie){
    CinemaRoom::playMovie(movie);
    armchairTurnOn();
}

string CinemaRoom4D::getRoomTypeName(){
    return "Cinema Room 4D "+(playingMovie!=NULL?("Playing movie : "+playingMovie->getTitle()):"Not Playing movie" );
}

void CinemaRoom4D::armchairTurnOn() {
    isArmchairOn = true;
    cout << "Armchairs are turn on." << endl;
}

void CinemaRoom4D::armchairTurnOnFromConsole() {
string yesNo;
if (isArmchairOn == false) {
    cout << "Armchairs are turn off. Would you like to turn on them? (Write y or n)" << endl;
    do {
        cin >> yesNo;
        if (yesNo == "y") {
            cout << "Now armchairs are turn on." << endl;
            isArmchairOn = true;
        } else  if (yesNo == "n") {
            cout << "Still armchairs are turn off." << endl;
        } else {
            cout << "It is wrong answer. Try again." << endl;
        }
    } while (yesNo != "y" && yesNo != "n");
} else {
    cout << "Armchairs have been turn on." << endl;
}

}

void CinemaRoom4D::armchairTurnOff(){
    isArmchairOn = false;
    cout << "Armchairs have been turn off." << endl;
}

//This method is called when movie is finished and all devices in cinema room are turn off
void CinemaRoom4D::closeAllInRoom() {
    CinemaRoom::closeAllInRoom();
    armchairTurnOff();
}

void CinemaRoom4D::readParamsFromConsole() {
    CinemaRoom::readParamsFromConsole();
    if (playingMovie!=NULL) {
    armchairTurnOn();
    } 
 }