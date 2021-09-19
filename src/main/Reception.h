#pragma once

#include "Events.h"
#include "Database.h"

class Reception {
private:
    static bool processForRooms(const Event &event);

    static bool processForRoom(const Event &event, const string &roomName);

public:

    static bool process(const Event &event, const string &roomName = "");

    static void print() {
        Database::print();
    }
};