#include "MovieSystem.h"
#include <iostream>
#include <string>

using namespace std;

MovieSystem::MovieSystem() {

    Movie m;
    m.title = "Inception";
    m.genre = "Sci-Fi";
    m.language = "English";
    m.releaseDate = "2010";

    Show s;
    s.time = "18:00";
    s.hallName = "Hall 1";
    s.seats.resize(5, vector<Seat>(5));

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            if (i < 2) s.seats[i][j].type = SILVER;
            else if (i < 4) s.seats[i][j].type = GOLD;
            else s.seats[i][j].type = PLATINUM;
            s.seats[i][j].isBooked = false;
        }

    m.shows.push_back(s);
    movies.push_back(m);
}

void MovieSystem::showMovies() {
    cout << "\n=== Available Movies ===\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title << " [" << movies[i].genre << "] (" << movies[i].language << ") - Released: " << movies[i].releaseDate << "\n";
    }
}

void MovieSystem::selectMovieAndShow() {
    showMovies();
    cout << "Select a movie (number): ";
    cin >> selectedMovieIndex;
    selectedMovieIndex--;

    if (selectedMovieIndex < 0 || selectedMovieIndex >= (int)movies.size()) {
        cout << "Invalid selection.\n";
        selectedMovieIndex = -1;
        return;
    }

    const auto& m = movies[selectedMovieIndex];
    cout << "Available shows for " << m.title << ":\n";
    for (size_t i = 0; i < m.shows.size(); ++i) {
        cout << i + 1 << ". Time: " << m.shows[i].time << " | Hall: " << m.shows[i].hallName << "\n";
    }

    cout << "Select a show: ";
    cin >> selectedShowIndex;
    selectedShowIndex--;

    if (selectedShowIndex < 0 || selectedShowIndex >= (int)m.shows.size()) {
        cout << "Invalid show selection.\n";
        selectedShowIndex = -1;
    }
    else {
        cout << "Show selected successfully!\n";
    }
}

Movie& MovieSystem::getSelectedMovie() {
    return movies[selectedMovieIndex];
}

Show& MovieSystem::getSelectedShow() {
    return movies[selectedMovieIndex].shows[selectedShowIndex];
}

bool MovieSystem::hasSelection() {
    return selectedMovieIndex >= 0 && selectedShowIndex >= 0;
}



void MovieSystem::adminMenu() {
    int choice;
    do {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Add Movie\n";
        cout << "2. Delete Movie\n";
        cout << "3. Add Show\n";
        cout << "4. Delete Show\n";
        cout << "5. Update Show\n";
        cout << "6. Exit Admin Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMovie();
            break;
        case 2:
            deleteMovie();
            break;
        case 3:
            addShow();
            break;
        case 4:
            deleteShow();
            break;
        case 5:
            updateShow();
            break;
        case 6:
            cout << "Exiting Admin Menu.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

void MovieSystem::addMovie() {
    Movie newMovie;
    cout << "Enter movie title: ";
    cin.ignore();
    getline(cin, newMovie.title);

    cout << "Enter genre: ";
    getline(cin, newMovie.genre);

    cout << "Enter language: ";
    getline(cin, newMovie.language);

    cout << "Enter release date (year): ";
    getline(cin, newMovie.releaseDate);

    movies.push_back(newMovie);
    cout << "Movie added successfully!\n";
}

void MovieSystem::deleteMovie() {
    showMovies();
    cout << "Select a movie to delete (number): ";
    int index;
    cin >> index;
    index--;

    if (index < 0 || index >= (int)movies.size()) {
        cout << "Invalid movie selection.\n";
        return;
    }

    movies.erase(movies.begin() + index);
    cout << "Movie deleted successfully!\n";

    if (selectedMovieIndex == index) {
        selectedMovieIndex = -1;
        selectedShowIndex = -1;
    }
}

void MovieSystem::addShow() {
    showMovies();
    cout << "Select movie to add show for (number): ";
    int movieIndex;
    cin >> movieIndex;
    movieIndex--;

    if (movieIndex < 0 || movieIndex >= (int)movies.size()) {
        cout << "Invalid movie selection.\n";
        return;
    }

    Show newShow;
    cout << "Enter show time (e.g., 18:00): ";
    cin.ignore();
    getline(cin, newShow.time);

    cout << "Enter hall name: ";
    getline(cin, newShow.hallName);

    int rows = 5, cols = 5;
    newShow.seats.resize(rows, vector<Seat>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i < 2) newShow.seats[i][j].type = SILVER;
            else if (i < 4) newShow.seats[i][j].type = GOLD;
            else newShow.seats[i][j].type = PLATINUM;
            newShow.seats[i][j].isBooked = false;
        }
    }

    movies[movieIndex].shows.push_back(newShow);
    cout << "Show added successfully!\n";
}

void MovieSystem::deleteShow() {
    showMovies();
    cout << "Select movie to delete show from (number): ";
    int movieIndex;
    cin >> movieIndex;
    movieIndex--;

    if (movieIndex < 0 || movieIndex >= (int)movies.size()) {
        cout << "Invalid movie selection.\n";
        return;
    }

    if (movies[movieIndex].shows.empty()) {
        cout << "No shows to delete for this movie.\n";
        return;
    }

    cout << "Shows for " << movies[movieIndex].title << ":\n";
    for (size_t i = 0; i < movies[movieIndex].shows.size(); ++i) {
        cout << i + 1 << ". Time: " << movies[movieIndex].shows[i].time << " | Hall: " << movies[movieIndex].shows[i].hallName << "\n";
    }

    cout << "Select show to delete (number): ";
    int showIndex;
    cin >> showIndex;
    showIndex--;

    if (showIndex < 0 || showIndex >= (int)movies[movieIndex].shows.size()) {
        cout << "Invalid show selection.\n";
        return;
    }

    movies[movieIndex].shows.erase(movies[movieIndex].shows.begin() + showIndex);
    cout << "Show deleted successfully!\n";


    if (selectedMovieIndex == movieIndex && selectedShowIndex == showIndex) {
        selectedShowIndex = -1;
    }
}

void MovieSystem::updateShow() {
    showMovies();
    cout << "Select movie to update show for (number): ";
    int movieIndex;
    cin >> movieIndex;
    movieIndex--;

    if (movieIndex < 0 || movieIndex >= (int)movies.size()) {
        cout << "Invalid movie selection.\n";
        return;
    }

    if (movies[movieIndex].shows.empty()) {
        cout << "No shows available for this movie.\n";
        return;
    }

    cout << "Shows for " << movies[movieIndex].title << ":\n";
    for (size_t i = 0; i < movies[movieIndex].shows.size(); ++i) {
        cout << i + 1 << ". Time: " << movies[movieIndex].shows[i].time << " | Hall: " << movies[movieIndex].shows[i].hallName << "\n";
    }

    cout << "Select show to update (number): ";
    int showIndex;
    cin >> showIndex;
    showIndex--;

    if (showIndex < 0 || showIndex >= (int)movies[movieIndex].shows.size()) {
        cout << "Invalid show selection.\n";
        return;
    }

    Show& show = movies[movieIndex].shows[showIndex];
    cin.ignore();

    cout << "Current time: " << show.time << "\nEnter new time (or press enter to keep current): ";
    string newTime;
    getline(cin, newTime);
    if (!newTime.empty()) {
        show.time = newTime;
    }

    cout << "Current hall: " << show.hallName << "\nEnter new hall name (or press enter to keep current): ";
    string newHall;
    getline(cin, newHall);
    if (!newHall.empty()) {
        show.hallName = newHall;
    }

    cout << "Show updated successfully!\n";
}
