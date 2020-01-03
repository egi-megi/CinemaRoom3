#include "CinemaRoom.h"
#include "Room.h"
#include "Aircondition.h"
#include "Projector.h"
#include "Screen.h"
#include "Sound.h"
#include "Movie.h"
#include <iostream>

using namespace std;

CinemaRoom::CinemaRoom()
{
    projectorDigital = new Projector("digital");
    projectorAnalog = NULL;
    playingMovie = NULL;
    roomType = "Cinema Room";
    cout << "Constructor of CinemaRoom class is called." << endl;
}

CinemaRoom::CinemaRoom(const CinemaRoom &cinemaRoom)
{
    aircondition = cinemaRoom.aircondition;
    projectorDigital = cinemaRoom.projectorDigital;
    projectorAnalog = cinemaRoom.projectorAnalog;
    screen = cinemaRoom.screen;
    sound = cinemaRoom.sound;
    playingMovie = cinemaRoom.playingMovie;
    cout << "Called coping constructor for CinemaRoom." << endl;
}

CinemaRoom::~CinemaRoom()
{
    cout << "Destructor of CinemaRoom object is called." << endl;
}

string CinemaRoom::getRoomTypeName()
{
    return "Cinema Room " + (playingMovie != NULL ? ("Playing movie : " + playingMovie->getTitle()) : "Not Playing movie");
}


//This method turn on and set all things when the movie is started
void CinemaRoom::playMovie(Movie *movie)
{
    // Exeption if movie is NULL
    if (movie == NULL)
    {
        cout << "There is no movie to play. Movie should't be NULL.";
        return;
    }
    cout << "The movie "<< movie->getTitle() << " is choosen. Everything in cinema room is turn on." << endl;
    //Chossing type of projector depending on what projector is needed to play movie
    if (movie->getProjectorTypeInThisMovie() == "digital" && projectorDigital == NULL)
    {
        cout << "Missing digital projector. Movie can not be playing." << endl;
        return;
    }
    if (movie->getProjectorTypeInThisMovie() == "analog" && projectorAnalog == NULL)
    {
        cout << "Missing analog projector. Movie can not be playing." << endl;
        return;
    }
    playingMovie = movie;
    playingMovie->setIsPlaying(true);
    //trunOnAircondition();
    //aircondition.setValueOfAircondition();
    screen.setProportionOfScreenWidth(playingMovie->getProportionOfScreenWidthForMovie());
    screen.setProportionOfScreenHeight(playingMovie->getProportionOfScreenHeightForMovie());
    screen.computeWidthOfScreen();
    sound.turnOn();
    sound.setSoundLevel(playingMovie->getMovieSoundLevel());
    if (playingMovie->getProjectorTypeInThisMovie() == "digital")
    {
        projectorDigital->turnOn();
    }
    if (playingMovie->getProjectorTypeInThisMovie() == "analog")
    {
        projectorAnalog->turnOn();
    }
}

//This method is called when movie is finished and all devices in cinema room are turn off
void CinemaRoom::closeAllInRoom()
{
    cout << "Movie is ended. Everything in " << roomType << " is turn off." << endl;
    if (playingMovie != NULL)
    {
        if (playingMovie->getProjectorTypeInThisMovie() == "digital")
        {
            projectorDigital->turnOff();
        }
        if (playingMovie->getProjectorTypeInThisMovie() == "analog")
        {
            projectorAnalog->turnOff();
        }
        playingMovie->setIsPlaying(false);
    }
    sound.turnOff();
    turnOffAircondition();
}

// Method for getting new projector in cinema room
void CinemaRoom::operator+=(Projector *proj)
{
    if (proj->getProjectorType() == "digital")
    {
        if (projectorDigital == NULL)
        {
            projectorDigital = proj;
            cout << "There is " << projectorDigital->getProjectorType() << " projector set in this cinema room." << endl;
        }
        else
        {
            cout << "Cinema room has already " << projectorDigital->getProjectorType() << " projector." << endl;
        }
    }
    if (proj->getProjectorType() == "analog")
    {
        if (projectorAnalog == NULL)
        {
            projectorAnalog = proj;
        }
        else
        {
            cout << "Cinema room has " << projectorAnalog->getProjectorType() << " projector." << endl;
        }
    }
}

// Method used for example when projector is borken and must be removed
void CinemaRoom::operator-=(Projector *projDel)
{
    if (projDel->getProjectorType() == "digital")
    {
        if (projectorDigital != NULL)
        {
            cout << "Projector " << projectorDigital->getProjectorType() << " was removed." << endl;
            projectorDigital = NULL;
        }
        else
        {
            cout << "Cinema room has no" << projectorDigital->getProjectorType() << " projector." << endl;
        }
    }
    if (projDel->getProjectorType() == "analog")
    {
        if (projectorAnalog != NULL)
        {
            cout << "Projector " << projectorAnalog->getProjectorType() << " was removed." << endl;
            projectorAnalog = NULL;
        }
        else
        {
            cout << "Cinema room has no" << projectorAnalog->getProjectorType() << " projector." << endl;
        }
    }
}

bool CinemaRoom::operator==(CinemaRoom const &ro1) const
{
    if (Room::operator==(ro1) /* && co tam jeszce chce*/)
    {
        cout << "Saved object and read object are equal." << endl;
        return true;
    }
    else
    {
        cout << "Saved object and read object are not equal." << endl;
        return false;
    }
}

void CinemaRoom::readParamsFromConsole()
{
    Room::readParamsFromConsole();
    if (playingMovie != NULL)
    {
        cout << "Turn off the movie" << endl;
        closeAllInRoom();
        playingMovie = NULL;
    }
    else
    {
        Movie *m = new Movie;
        m->readMovieFromConsole();
        playMovie(m);
    }
    //Screen *s = new Screen;
    //s->readHeightOfScreenForCinemaRoomFromConsole();
}

void CinemaRoom::write(ostream &os) const
{
    cout << "Saving ciname room" << endl;
    Room::write(os);
    if (playingMovie != NULL)
    {
        os << 1 << endl;
        os << aircondition;
        os << *playingMovie;
    }
    else
    {
        os << 0 << endl;
    }
}

void CinemaRoom::read(istream &is)
{
    Room::read(is);
    int hasM;
    is >> hasM;
    if (hasM == 1)
    {
        is >> aircondition;
        Movie *m = new Movie();
        is >> *m;
        playingMovie = m;
    }
}



