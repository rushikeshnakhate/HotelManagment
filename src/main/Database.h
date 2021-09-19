#pragma once

#include "Rooom.h"
#include <vector>
#include <algorithm>
#include <iostream>

using HotelRegister = std::vector<Room>;


class Database {
    static constexpr int rooms_on_floor{2};
    static constexpr int number_of_floors{2};
    static constexpr char start_prefix = 'A';
    static constexpr char end_prefix = 'E';
    static HotelRegister hotelRegister;
public:
    static const HotelRegister &getHotelRegister() {
        return hotelRegister;
    }

    static void init();

    static void print() {
        std::for_each(hotelRegister.begin(), hotelRegister.end(), [](const Room &room) {
            std::cout << " roomName=" << room.roomName
                      << " status=" << room.roomStatus << std::endl;
        });
    };
};





