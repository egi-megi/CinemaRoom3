#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

using namespace std;

class Movie
{
    public:
        Movie();
        virtual ~Movie();
        Movie& operator=(Movie const& mov);
        string getTitle();
        void setTitle();
        void setTitle(string title);
        string getKindOfMovie();
        void setKindOfMovie(string kindOfM);
        int getMovieSoundLevel();
        //void setMovieDefaultSoundLevel(int movieSoundLevel);
        void setMovieSoundLevel(int msl);
        string getProjectorTypeInThisMovie();
        void setProjectorTypeInThisMovie(string projectorType);
        int getProportionOfScreenHeightForMovie();
        void setProportionOfScreenHeightForMovie(int proportionOfScreenHeightForMovie);
        int getProportionOfScreenWidthForMovie();
        void setProportionOfScreenWidthForMovie(int proportionOfScreenWidthForMovie);
        bool getIsPlaying();
        void setIsPlaying(bool isPlaying);
        void playMovie(Movie * movie);
        void readMovieFromConsole();

        friend ostream & operator<<(ostream & os, const Movie & m);
        friend istream & operator>>(istream & is, Movie & mm);
    protected:
    private:
        string title;
        string kindOfMovie;
        int movieSoundLevel;
        string projectorTypeInThisMovie;
        int proportionOfScreenHeightForMovie;
        int proportionOfScreenWidthForMovie;
        bool isPlaying;
};

#endif // MOVIE_H
