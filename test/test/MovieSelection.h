#ifndef MOVIE_SELECTION_H
#define MOVIE_SELECTION_H

#include <string>
#include <vector>

class MovieSelection {
private:
    std::vector<std::string> movies;
    std::string selectedMovie;

public:
    MovieSelection();
    void displayMovies();
    void selectMovie();
    std::string getSelectedMovie();
    bool isMovieSelected();
};

#endif
