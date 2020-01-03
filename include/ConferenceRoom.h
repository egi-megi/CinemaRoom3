#ifndef CONFERENCEROOM_H
#define CONFERENCEROOM_H
#include <Room.h>
#include <Aircondition.h>
#include <Projector.h>
#include <Screen.h>
#include <Company.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

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
        void setNumberOfChairs();
        int getNumberOfChairs();
        void readNumberOfChairs();
        void readListOfCompaniesFromConsole();
        string getRoomTypeName();
        void write(ostream & os) const;
        void read(istream &is);
        void operator+= (Projector* proj);
        void operator-= (Projector* projDel);
        bool operator== (ConferenceRoom const & cro1) const;

       // bool sortByName(const Company &c1, const Company & c2);
        //bool sortByRentDay(const Company &c1, const Company & c2);
        //bool operator<(const Company &c1, const Company & c2);
        //void showList(const Company & cc);
    protected:
        Projector *projectorDigital;
        Screen screen;
        Sound sound;
        
    private:
        bool areWindowsOpen;
        int chairNumber;
};
bool sortByName(const Company &c1, const Company & c2);
bool sortByRentDay(const Company &c1, const Company & c2);
void showListName(const Company & cc);
void showListDay(const Company & cc);


#endif // CINEMAROOM_H
