#pragma once

#include <string>

using RoomName = std::string;
using RoomStatusHolder = std::string;

struct Room {
    RoomStatusHolder roomStatus;
    RoomName roomName;

    Room(RoomName roomName, RoomStatusHolder roomStatus) : roomName(std::move(roomName)),
                                                           roomStatus(std::move(roomStatus)) {};

};;