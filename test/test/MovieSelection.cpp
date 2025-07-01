#include "MovieSelection.h"
#include <iostream>

using namespace std;

MovieSelection::MovieSelection() {
    movies = {
        "Avengers: Endgame",
        "Oppenheimer",
        "Spider-Man: No Way Home",
        "The Matrix",
        "Interstellar"
    };
    selectedMovie = "";
}

void MovieSelection::displayMovies() {
    cout << "\n🎞️ Available Movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
}

void MovieSelection::selectMovie() {
    displayMovies();
    int choice;
    cout << "Select a movie by number: ";
    cin >> choice;

    if (choice >= 1 && choice <= (int)movies.size()) {
        selectedMovie = movies[choice - 1];
        cout << "🎬 You selected: " << selectedMovie << endl;
    }
    else {
        cout << "⚠️ Invalid choice. Try again.\n";
        selectMovie();
    }
}

string MovieSelection::getSelectedMovie() {
    return selectedMovie;
}

bool MovieSelection::isMovieSelected() {
    return !selectedMovie.empty();
}