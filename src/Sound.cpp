#include "Sound.h"
#include "Movie.h"

Sound::Sound()
{
    isTurnOn = false;
    soundLevel = 0;
    cout << "Constructor of Sound class is called." << endl;
}

Sound::~Sound()
{
    cout << "Destructor of Sound object is called." << endl;
}

void Sound::turnOn(){
   isTurnOn=true;
   cout << "Sound is turn on." << endl;
}

void Sound::turnOff(){
    isTurnOn=false; 
    cout << "Sound is turn off." << endl;
}

void Sound::setSoundLevel(int sl) 
{
soundLevel = sl;
}

void Sound::setSoundLevelFromMovie(Movie *movie)
{
    soundLevel = movie->getMovieSoundLevel();
}

int Sound::getSoundLevel() 
{
cout << "Sound level is: "; 
  return soundLevel;
}

void Sound::readSoundLevelFromConsole()
{
  cout << "For this movie default value of sound level is: " << soundLevel;
  string yesNo;
  cout << "Would you like to change this sound level? (Write y or n)" << endl;
  cin >> yesNo;
  if (yesNo == "y") {
    cout << "Write what sound level would you like to set: " << endl;
    cin >> soundLevel;
    cout << "You set sound level: " << soundLevel << endl;
  }
}

ostream & operator<<(ostream & os, const Sound& s) {
    os << s.isTurnOn << endl;
    os << s.soundLevel << endl;
    return os;
}

istream & operator>>(istream &is, Sound & ss) {
    is >> ss.isTurnOn;
    is >> ss.soundLevel;
    return is;
}