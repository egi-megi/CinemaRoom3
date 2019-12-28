#ifndef SOUND_H
#define SOUND_H
#include "Movie.h"


class Sound
{
    public:
        Sound();
        virtual ~Sound();
        void turnOn();
        void turnOff();
        int getSoundLevel();
        void setSoundLevel(int sl);
        void setSoundLevelFromMovie(Movie *movie);
        void readSoundLevelFromConsole();

        friend ostream & operator<<(ostream & os, const Sound & s);
        friend istream & operator>>(istream & is, Sound & ss);
    protected:
    private:
    bool isTurnOn;
    int soundLevel;
};

#endif // SOUND_H
