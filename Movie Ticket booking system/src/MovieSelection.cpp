#include "MovieSelection.h"
#include <iostream>

using namespace std;

MovieSelection::MovieSelection() {
    movies = { "Inception", "Avengers: Endgame", "Interstellar", "The Dark Knight" };
}

void MovieSelection::displayMovies() {
    cout << "Available Movies:\n";
    for (size_t i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
}

string MovieSelection::selectMovie() {
    int choice;
    displayMovies();
    cout << "Select a movie by number: ";
    cin >> choice;

    if (choice >= 1 && choice <= (int)movies.size()) {
        return movies[choice - 1];
    }
    else {
        cout << "Invalid selection. Try again.\n";
        return selectMovie();
    }
}