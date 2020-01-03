#ifndef SCREEN_H
#define SCREEN_H
#include "Movie.h"

class Screen
{
    public:
        Screen();
        virtual ~Screen();
        int getProportionOfScreenHeight();
        void setProportionOfScreenHeight(int proportionOfScreenHeight);
        int getProportionOfScreenWidth();
        void setProportionOfScreenWidth(int proportionOfScreenWidth);
        int getHeightOfScreen();
        void setHeightOfScreen(int heightOfScreen);
        void setProportionOfScreenFromMovie(Movie *movie);
        void readHeightOfScreenForCinemaRoomFromConsole();
        int getWidthOfScreen();
        void computeWidthOfScreen();

        friend ostream & operator<<(ostream & os, const Screen & s);
        friend istream & operator>>(istream & is, Screen & sc);
    protected:
    private:
        int proportionOfScreenHeight;
        int proportionOfScreenWidth;
        int heightOfScreen;
        int widthOfScreen;
};

#endif // SCREEN_H
