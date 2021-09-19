#pragma once

#include "Rooom.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using HotelRegister = std::vector<Room>;

//This class should be singleton and thread safe
//For simplicity making it static now
class Database {
    static constexpr int rooms_on_floor{5};
    static constexpr int number_of_floors{4};
    static constexpr char start_prefix = 'A';
    static constexpr char end_prefix = 'E';
    static HotelRegister hotelRegister;
public:
    static const HotelRegister &getHotelRegister() {
        return hotelRegister;
    }

    static void init();

    inline static auto print = []() {
        std::for_each(hotelRegister.begin(), hotelRegister.end(), [](const Room &room) {
            std::cout << " roomName=" << room.roomName
                      << " status=" << room.roomStatus->getStatus() << std::endl;
        });
    };

    static void updateRoomStatusByName(const RoomName &roomName, RoomStatusHolder &roomStatus) {
        auto itr = findRoomByName(roomName);
        itr->roomStatus = move(roomStatus);
    }

    static vector<Room>::iterator findRoomByName(const RoomName &roomName) {
        auto itr = find_if(hotelRegister.begin(), hotelRegister.end(),
                           bind(Room::findByName, placeholders::_1, roomName));
        return itr;
    }
};





