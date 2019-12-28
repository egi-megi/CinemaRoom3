#ifndef CINEMAROOM4D_H
#define CINEMAROOM4D_H
#include <Room.h>
#include <CinemaRoom.h>
#include <Aircondition.h>
#include <Movie.h>
#include <Projector.h>
#include <Screen.h>
#include <Sound.h>
#include <iostream>

using namespace std;

class CinemaRoom4D: public CinemaRoom
{
    public:
        CinemaRoom4D();
        CinemaRoom4D (const CinemaRoom4D &cinemaRoom4D);
        virtual ~CinemaRoom4D();
        void playMovie(Movie *movie);
        virtual void closeAllInRoom();
        void readParamsFromConsole();
        void armchairTurnOn();
        void armchairTurnOnFromConsole();
        void armchairTurnOff();
        string getRoomTypeName();
        void operator+= (Projector* proj);
        void operator-= (Projector* projDel);
        bool operator==(CinemaRoom4D const & cro1) const;

    protected:
        bool isArmchairOn;
    private:
};

#endif // CINEMAROOM4D_H