#ifndef CINEMAROOM_H
#define CINEMAROOM_H
#include <Room.h>
#include <Aircondition.h>
#include <Movie.h>
#include <Projector.h>
#include <Screen.h>
#include <Sound.h>
#include <iostream>

using namespace std;

class CinemaRoom: public Room
{
    public:
        CinemaRoom();
        CinemaRoom (const CinemaRoom &cinemaRoom);
        virtual ~CinemaRoom();
        //Aircondition aircondition;
       
       Movie *playingMovie;
        virtual void playMovie(Movie *movie);
        virtual void closeAllInRoom();
        virtual void readParamsFromConsole();
        virtual string getRoomTypeName();
        //void trunOnAircondition();
        //void turnOffAircondition();
        void checkTemperature();
        virtual void write(ostream & os) const;
        virtual void read(istream &is);
        void operator+= (Projector* proj);
        void operator-= (Projector* projDel);
        bool operator==(CinemaRoom const & cro1) const;
       
    protected:
     
    private:
        //Aircondition aircondition;
        Projector *projectorDigital;
        Projector *projectorAnalog;
        Screen screen;
        Sound sound;
};

#endif // CINEMAROOM_H
