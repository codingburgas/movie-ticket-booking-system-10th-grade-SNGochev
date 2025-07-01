#ifndef SEAT_BOOKING_H
#define SEAT_BOOKING_H

#include "MovieData.h"

class SeatBooking {
public:
    void displaySeats(const Show& show);
    void bookSeats(Show& show);
    int calculatePrice(SeatType type);
};

#endif
