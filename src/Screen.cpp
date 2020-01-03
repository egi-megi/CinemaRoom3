#include "Screen.h"
#include <iostream>

using namespace std;

Screen::Screen()
{
  proportionOfScreenHeight = 9;
  proportionOfScreenWidth = 16;
  heightOfScreen = 5;
  cout << "Constructor of Screen class is called." << endl;
}

Screen::~Screen()
{
    cout << "Destructor of Screen object is called." << endl;
}

int Screen::getProportionOfScreenHeight() {
  //cout << "Proportion of screen's height is: " << proportionOfScreenHeight << endl;
  return proportionOfScreenHeight;
}

void Screen::setProportionOfScreenHeight(int psh) {
  //cout << "Proportion of screen's height should be set to: " << proportionOfScreenHeight << endl;
  proportionOfScreenHeight = psh;
}

int Screen::getProportionOfScreenWidth() {
  //cout << "Proportion of screen's width is: " << proportionOfScreenWidth << endl;
  return proportionOfScreenWidth;
}

void Screen::setProportionOfScreenWidth(int psw) {
  //cout << "Proportion of screen's width should be set to: " << proportionOfScreenWidth << endl;
  proportionOfScreenWidth = psw;
}

int Screen::getHeightOfScreen() {
  return heightOfScreen;
}

void Screen::setHeightOfScreen(int hs) {
  heightOfScreen = hs;
}

void Screen::setProportionOfScreenFromMovie(Movie *movie)
{
    proportionOfScreenHeight = movie->getProportionOfScreenHeightForMovie();
    proportionOfScreenWidth = movie->getProportionOfScreenWidthForMovie();
}

/*void Screen::readHeightOfScreenForCinemaRoomFromConsole() {
  cout << "Would you like to watch movie on screen with height: 4, 5 or 6 meteres? (Write 4, 5 or 6)" << endl;
  while (cin >> heightOfScreen)
  {
  try {
    computeWidthOfScreen();
  }
  catch (const char * s)
  {
    cout << s << endl;
    cout << "Write height of screen 4, 5 or 6." << endl;
    continue;
  }

  cout << "You choose Room with screen, which is " << heightOfScreen << " metres.";
  computeWidthOfScreen();
  cout << "So for the movie, which you choose, the width of screen will be set on " << widthOfScreen << " meters." << endl;
  cout << "You can choose another height of screen or go out of this option by \"e\":";
}
}*/

int Screen::getWidthOfScreen() {
  return widthOfScreen;
}

int Screen::computeWidthOfScreen() {
  //widthOfScreen = static_cast<double>((propWidth * heightOfScreen)/propHeight);
  //if (heightOfScreen != 4)
  //throw "Height of screen should 4, 5 or 6 meteres.";
  widthOfScreen = ((proportionOfScreenWidth * heightOfScreen)/proportionOfScreenHeight);
  if (widthOfScreen%10 != 0) {
    widthOfScreen+=1;
  }
return widthOfScreen;
}

ostream & operator<<(ostream & os, const Screen& sc) {
    os << sc.heightOfScreen << endl;
    os << sc.widthOfScreen << endl;
    return os;
}

istream & operator>>(istream &is, Screen & sce) {
    is >> sce.heightOfScreen;
    is >> sce.widthOfScreen;
    return is;
}