#include "Reception.h"
#include "Database.h"

bool Reception::processForRooms(const Event &event) {
    for (auto const &room : Database::getHotelRegister()) {
        if (processForRoom(event, room.roomName))
            return true;
    }
}

bool Reception::processForRoom(const Event &event, const string &roomName) {
    auto itr = Database::findRoomByName(roomName);
    if (itr != Database::getHotelRegister().end()) {
        auto result = itr->roomStatus->onEvent(event, roomName);
        if (result) {
            cout << event << " is Success, for room ='" << itr->roomName << "'" << endl;
            Database::updateRoomStatusByName(itr->roomName, result);
            return true;
        }
        return false;
    }
    return false;
}


bool Reception::process(const Event &event, const string &roomName) {
    if (roomName.empty())
        return processForRooms(event);
    else
        return processForRoom(event, roomName);
}
