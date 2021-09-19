#pragma once

#include <string>
#include "StateMachine.h"

struct Room {
    RoomStatusHolder roomStatus;
    RoomName roomName;

    Room(RoomName roomName, RoomStatusHolder roomStatus) : roomName(std::move(roomName)),
                                                           roomStatus(std::move(roomStatus)) {};


    static bool findByName(const Room &room, const RoomName &roomName) {
        return room.roomName == roomName;
    }
};;