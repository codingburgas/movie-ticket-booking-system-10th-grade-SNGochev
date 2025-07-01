#include <iostream>
#include "LoginSystem.h"
#include "SeatBooking.h"
#include "MovieSystem.h"

using namespace std;


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    clearScreen();

    LoginSystem login;
    login.loginUser();

    clearScreen();

    MovieSystem movieSys;
    SeatBooking booking;

    string username = login.getUsername();
    bool isAdmin = (username == "admin");

    while (true) {
        cout << "\n=== Main Menu ===\n";
        cout << "1. View Movies\n";
        cout << "2. Select Movie & Show\n";
        cout << "3. View Seats\n";
        cout << "4. Book Seats\n";
        if (isAdmin) {
            cout << "5. Admin Menu\n";
            cout << "6. Exit\n";
        }
        else {
            cout << "5. Exit\n";
        }

        cout << "Choose option: ";
        int choice;
        cin >> choice;

        clearScreen();

        switch (choice) {
        case 1:
            movieSys.showMovies();
            break;
        case 2:
            movieSys.selectMovieAndShow();
            break;
        case 3:
            if (movieSys.hasSelection())
                booking.displaySeats(movieSys.getSelectedShow());
            else
                cout << "⚠️ Please select a movie and show first.\n";
            break;
        case 4:
            if (movieSys.hasSelection())
                booking.bookSeats(movieSys.getSelectedShow());
            else
                cout << "⚠️ Please select a movie and show first.\n";
            break;
        case 5:
            if (isAdmin) {
                movieSys.adminMenu();
                break;
            }
            else {
                cout << "👋 Goodbye!\n";
                return 0;
            }
        case 6:
            if (isAdmin) {
                cout << "👋 Goodbye!\n";
                return 0;
            }
        default:
            cout << "❌ Invalid choice.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        clearScreen();
    }
}