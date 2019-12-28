#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H
#include <Room.h>
#include <Aircondition.h>
#include <Projector.h>
#include <Screen.h>
#include <iostream>

using namespace std;

class ConferenceRoom: public Room
{
    public:
        ConferenceRoom();
        ConferenceRoom (const ConferenceRoom &conferenceRoom);
        virtual ~ConferenceRoom();
        void closeAllInRoom();
        void readParamsFromConsole();
        void readOpenCloseWindowsFromConsole();
        void openWindows();
        void closeWindows();
        string getRoomTypeName();
        void operator+= (Projector* proj);
        void operator-= (Projector* projDel);
        bool operator== (ConferenceRoom const & cro1) const;
    protected:
        Projector *projectorDigital;
        Screen screen;
        Sound sound;
    private:
        bool areWindowsOpen;
};

#endif // CINEMAROOM_H
