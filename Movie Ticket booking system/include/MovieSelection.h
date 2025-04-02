#ifndef MOVIE_SELECTION_H
#define MOVIE_SELECTION_H

#include <vector>
#include <string>

class MovieSelection {
private:
    std::vector<std::string> movies;
public:
    MovieSelection();
    void displayMovies();
    std::string selectMovie();
};

#endif