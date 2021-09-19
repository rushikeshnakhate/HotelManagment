
#include "Database.h"

HotelRegister Database::hotelRegister;

void Database::init() {
    auto plus = [&](char prefix) { return prefix + 1; };
    auto minus = [&](char prefix) { return prefix - 1; };

    auto add_rooms_to_floor = [&](char prefix, int floor, const auto &lambda) {
        for (int room = 1; room <= rooms_on_floor; room++) {
            hotelRegister.push_back(Room(std::to_string(floor) + prefix, ""));
            prefix = lambda(prefix);
        }
    };
    for (int floor = 1; floor <= number_of_floors; floor++) {
        if (floor % 2 != 0)
            add_rooms_to_floor(start_prefix, floor, plus);
        else
            add_rooms_to_floor(end_prefix, floor, minus);
    }
}