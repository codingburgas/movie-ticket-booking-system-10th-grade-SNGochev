#ifndef MOVIE_SYSTEM_H
#define MOVIE_SYSTEM_H

#include "MovieData.h"
#include <vector>

class MovieSystem {
private:
    std::vector<Movie> movies;
    int selectedMovieIndex = -1;
    int selectedShowIndex = -1;

public:
    MovieSystem();

    void showMovies();
    void selectMovieAndShow();
    Movie& getSelectedMovie();
    Show& getSelectedShow();
    bool hasSelection();


    void adminMenu();
    void addMovie();
    void deleteMovie();
    void addShow();
    void deleteShow();
    void updateShow();
};

#endif

