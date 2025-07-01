#include "SeatBooking.h"
#include <iostream>

using namespace std;

void SeatBooking::displaySeats(const Show& show) {
    cout << "\n=== Seat Layout (" << show.hallName << ") ===\n";
    for (size_t i = 0; i < show.seats.size(); ++i) {
        for (size_t j = 0; j < show.seats[i].size(); ++j) {
            char ch = show.seats[i][j].isBooked ? 'X' : 'O';
            cout << ch << " ";
        }
        cout << "  | Row " << i << "\n";
    }
    cout << "O = Available | X = Booked\n";
    cout << "Silver (0–1), Gold (2–3), Platinum (4)\n";
}

void SeatBooking::bookSeats(Show& show) {
    int n;
    cout << "How many seats do you want to book? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int r, c;
        cout << "Enter seat (row col): ";
        cin >> r >> c;

        if (r < 0 || r >= (int)show.seats.size() || c < 0 || c >= (int)show.seats[0].size()) {
            cout << "Invalid seat!\n";
            continue;
        }

        if (show.seats[r][c].isBooked) {
            cout << "Seat already booked!\n";
        }
        else {
            show.seats[r][c].isBooked = true;
            cout << "Seat booked! Price: $" << calculatePrice(show.seats[r][c].type) << "\n";
        }
    }
}

int SeatBooking::calculatePrice(SeatType type) {
    switch (type) {
    case SILVER: return 10;
    case GOLD: return 15;
    case PLATINUM: return 20;
    default: return 0;
    }
}
