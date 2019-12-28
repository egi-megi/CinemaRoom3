#ifndef ROOM_H
#define ROOM_H
#include <Aircondition.h>
#include <Movie.h>
#include <Projector.h>
#include <Screen.h>
#include <Sound.h>
#include <iostream>

using namespace std;

class Room
{
    public:
        Room();
        Room (const Room &room);
        virtual ~Room();

        virtual void readParamsFromConsole() ;
        virtual void closeAllInRoom() = 0;
        virtual void checkTemperature();
        virtual string getRoomTypeName()=0;
        //void trunOnAircondition();
        //void turnOffAircondition();
        void setNumberOfChairs();
        int getNumberOfChairs();
        virtual void write(ostream & os) const;
        virtual void read(istream &is);
        friend ostream & operator<<(ostream & os, const Room & sc);
        friend istream & operator>>(istream & is, Room & sce);
        bool operator==(Room const & ro1) const;
        //void operator+= (Projector* proj);
        //void operator-= (Projector* projDel);

        
    protected:
        TemperatureIndicator *tempIndicator;
        //Aircondition aircondition;
        int chairNumber;
    private:
        
};

#endif // CINEMAROOM_H