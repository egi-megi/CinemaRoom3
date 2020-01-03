#include "Movie.h"
#include <string>
#include <iostream>

using namespace std;

Movie::Movie()
{
    //title = t;
    kindOfMovie="2d";
    movieSoundLevel = 80;
    projectorTypeInThisMovie = "digital";
    proportionOfScreenHeightForMovie = 9;
    proportionOfScreenWidthForMovie = 16;
    isPlaying = false;
    cout << "Constructor of Movie class is called." << endl;
}

Movie::~Movie()
{
    cout << "Destructor of Movie object is called." << endl;
}

Movie& Movie::operator= (Movie const& mov)
{
     title = mov.title;
     return *this;
}

string Movie::getTitle() {
  //cout << "We will play movie: " << title << endl;
  return title;
}

void Movie::setTitle(string t) {
  title=t;
}

void Movie::setTitle() {
  //if (kindOfMovie == "2d") {
    string titleSymbol;
    cout << "Would you like to watch \"Powrót Jedi\" (write: pj) or \"Imperium kontratakuje\" (write: ik)?" << endl;
    do {
    cin >> titleSymbol;
    if (titleSymbol == "pj") {
     title = "\"Powrót Jedi\"";
     movieSoundLevel = 222;
    } else if (titleSymbol == "ik") {
      title = "\"Imperium kontratakuje\"";
      movieSoundLevel = 333;
    } else {
      cout << "You wrote wrong title. Please write it ones more." <<endl;
    }
  } while (titleSymbol != "pj" && titleSymbol != "ik");
}

string Movie::getKindOfMovie() {
  return kindOfMovie;
}

void Movie::setKindOfMovie(string kindOfM) {
  kindOfMovie = kindOfM;
}


int Movie::getMovieSoundLevel() 
{
  //cout << "For this movie the sound level is: " << movieSoundLevel << endl;
  return movieSoundLevel;
}

void Movie::setMovieSoundLevel(int msl){
  movieSoundLevel = msl;
}

/*void Movie::setDefaultMovieSoundLevel(int sl) {
  movieSoundLevel = sl;
  cout << "For movie \"" << Movie::title << "\" sound level should be set to: " << movieSoundLevel << endl;
}*/

/*void Movie::setMovieSoundLevel() {
  cout << "For this movie default value of sound level is: " << movieSoundLevel;
  string yesNo;
  cout << "Would you like to change this sound level? (Write y or n)" << endl;
  cin >> yesNo;
  if (yesNo == "y") {
    cout << "Write what sound level would you like to set: " << endl;
    cin >> movieSoundLevel;
    cout << "For movie " << title << " you set sound level: " << movieSoundLevel << endl;
  }
}*/

string Movie::getProjectorTypeInThisMovie() {
  //cout << "For movie " << Movie::title << "projector type is: " << projectorTypeInThisMovie << endl;
  return projectorTypeInThisMovie;
}

void Movie::setProjectorTypeInThisMovie(string pt) {
  cout << "For movie \"" << Movie::title << "\" projector type should be set to: " << projectorTypeInThisMovie << endl;
  projectorTypeInThisMovie = pt;
}

int Movie::getProportionOfScreenHeightForMovie() {
  //cout << "For movie " << Movie::title << "proportion of screen's height is: " << proportionOfScreenHeight << endl;
  return proportionOfScreenHeightForMovie;
}

void Movie::setProportionOfScreenHeightForMovie(int psh) {
  cout << "For movie \"" << Movie::title << "\" proportion of screen's height should be set to: " << proportionOfScreenHeightForMovie << endl;
  proportionOfScreenHeightForMovie = psh;
}

int Movie::getProportionOfScreenWidthForMovie() {
  //cout << "For movie " << Movie::title << "proportion of screen's width is: " << proportionOfScreenWidth << endl;
  return proportionOfScreenWidthForMovie;
}

void Movie::setProportionOfScreenWidthForMovie(int psw) {
  cout << "For movie \"" << Movie::title << "\" proportion of screen's width should be set to: " << proportionOfScreenWidthForMovie << endl;
  proportionOfScreenWidthForMovie = psw;
}

bool Movie::getIsPlaying(){
  return isPlaying;
}
void Movie::setIsPlaying(bool isp){
  isPlaying = isp;
  if (isp) {
    cout << "Movie is playing." << endl;
  } else {
   cout << "Movie is not playing." << endl;
  }
}

  void Movie::readMovieFromConsole() {
  setTitle();
  }

  ostream & operator<<(ostream & os, const Movie & m) {
    os << m.kindOfMovie << endl;
    os << m.title << endl;
    os << m.movieSoundLevel<< endl;
    os << m.projectorTypeInThisMovie << endl;
    os << m.proportionOfScreenHeightForMovie<< endl;
    os << m.proportionOfScreenWidthForMovie << endl;
    os << m.isPlaying<< endl;
    return os;
}

istream & operator>>(istream &is, Movie & m) {
    getline(is, m.kindOfMovie);
    getline(is, m.kindOfMovie);
    getline(is, m.title);
    is >> m.movieSoundLevel ;
    is >> m.projectorTypeInThisMovie ;
    is >> m.proportionOfScreenHeightForMovie ;
    is >> m.proportionOfScreenWidthForMovie ;
    is >> m.isPlaying ;
    return is;
}
  
  



