#include <iostream>
#include<fstream>
#include "Aircondition.h"
#include "TemperatureIndicator.h"
#include "Movie.h"
#include "CinemaRoom.h"
#include "ConferenceRoom.h"
#include "CinemaRoom4D.h"
#include "Room.h"

using namespace std;

bool saveAndReadFiles() {

    cout << endl;
    cout << "***** Check saving and reading files *****" << endl;

    CinemaRoom *cinemaRoom = new CinemaRoom();
        cout << "There is new cinema room." << endl;
    Movie *m = new Movie();
    m->setTitle("Powrot Jedi");
        cout << "The movie: ,," << m->getTitle() << "'' has been choosen." << endl;
    *cinemaRoom+=(new Projector("digital"));
    //Expected - playning movie 
    cinemaRoom->playMovie(m);
        if (cinemaRoom->playingMovie == NULL) {
            cout<<"Here should be a movie with projector, but the movie is not here." << endl;
        }
        cout << endl;
    ofstream fout;
    fout.open("Room.txt");
    cinemaRoom->setNumberOfChairs();
    cout << *cinemaRoom << endl;
    fout << *cinemaRoom;
    fout.close();
    ifstream fin;
    CinemaRoom c2;
    fin.open("Room.txt");
    fin>>c2;
    fin.close();
    
    if (*cinemaRoom == c2) {
        cout << "Saved objcet and read object are equal." << endl;
    } else {
        cout << "Saved objcet and read object are not equal." << endl;
    }
    
    cinemaRoom->closeAllInRoom();

    // Freeing dynamically allocated memory for m (Movie) and for cinemaRoom
    delete m;
    delete cinemaRoom;
    return true;
}






int testFunc()
    {
        if (!saveAndReadFiles())
        {
            cerr << "Error in playing movie";
            return 1;
        }
        /*if (!checkMovie())
        {
            cerr << "Error in Movie class";
            return 1;
        }
        if (!checkCinemaRoom())
        {
            cerr << "Error in CinemaRoom class";
            return 1;
        }
        if (!checkSettingAircondition()) 
        {
            cerr << "Error in checking settings of aircondition";
        }*/
        return 0;
    }
void save(Room** rooms) {
    ofstream fout;
    fout.open("Room.txt");
    for (int i = 0; i < 3; i++) {
        fout << *rooms[i];
    }
    fout.close();
}
void read(Room** rooms) {
    ifstream fin;
    fin.open("Room.txt");
      for (int i = 0; i < 3; i++) {
        fin >> *rooms[i];
    }
    fin.close();
}


int main()
{
    //testFunc();
    int lastKey;
    Room** rooms=new Room*[3];
    rooms[0]=new CinemaRoom();
    rooms[1]=new CinemaRoom4D();
    rooms[2]=new ConferenceRoom();
    do { //Main loop
        cout<<"Choose room to manage"<<endl;
        for (int i=0 ; i< 3; i++) {
            cout<<i<<" "<<rooms[i]->getRoomTypeName()<<endl;
        }
        cout << "7 - save all" << endl;
        cout << "8 - read" << endl;
        cout<<"9 - exit"<<endl;
        cin>>lastKey;
        if (cin.fail()) {
            lastKey=100;cin.clear();
            string s;
            cin>>s;
        }
        if (lastKey==9 || (lastKey<3 && lastKey >=0) || lastKey == 7 || lastKey == 8) {
            if (lastKey<3) {
                rooms[lastKey]->readParamsFromConsole();
            } 
            if (lastKey == 7) {
                save(rooms);
            }
            if (lastKey == 8) {
            read(rooms);
            }
        } else  {
            cout<<"unknown command"<<endl;
        }
    } while (lastKey!=9);
    for (int j=0 ; j<3; j++) {
        rooms[j]->closeAllInRoom();
    }
    
    return 0;
}