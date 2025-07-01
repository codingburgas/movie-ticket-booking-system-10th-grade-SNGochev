#ifndef MOVIE_DATA_H
#define MOVIE_DATA_H

#include <string>
#include <vector>
#include <map>

enum SeatType { SILVER, GOLD, PLATINUM };

struct Seat {
    SeatType type;
    bool isBooked;
};

struct Show {
    std::string time;
    std::vector<std::vector<Seat>> seats;
    std::string hallName;
};

struct Movie {
    std::string title;
    std::string genre;
    std::string language;
    std::string releaseDate;
    std::vector<Show> shows;
};

#endif

