#include "StateMachine.h"


//After checkin Available room become Occupied
RoomStatusHolder Available::onEvent(const Event &event, RoomName roomName) {
    if (event == Event::CheckIn) {
        return make_unique<Occupied>();
    }
    return nullptr;
}

//After CheckOut Available room become Vacant
RoomStatusHolder Occupied::onEvent(const Event &event, RoomName roomName) {
    if (event == Event::CheckOut) {
        return make_unique<Vacant>();
    }
    return nullptr;
}

//cleaning vacant room it become Available
//Repairing vacant room it become Repair
RoomStatusHolder Vacant::onEvent(const Event &event, RoomName roomName) {
    if (event == Event::Cleaning) {
        return make_unique<Available>();
    } else if (event == Event::Repairing) {
        return make_unique<Repair>();
    }
    return nullptr;
}

//Repairing completed become Available
RoomStatusHolder Repair::onEvent(const Event &event, RoomName roomName) {
    if (event == Event::RepairingCompleted) {
        return make_unique<Available>();
    }
    return nullptr;
}

