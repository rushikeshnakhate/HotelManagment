#pragma once

#include <memory>
#include <string>
#include "Events.h"

using namespace std;

using RoomName = std::string;

struct RoomStatus {

    virtual const string &getStatus() = 0;

    virtual unique_ptr<RoomStatus> onEvent(const Event &event, RoomName roomName = "") = 0;

    virtual ~RoomStatus() = default;
};

using RoomStatusHolder = unique_ptr<RoomStatus>;

struct Available : public RoomStatus {

    string status = "Available";

    const string &getStatus() override { return status; };

    RoomStatusHolder onEvent(const Event &event, RoomName roomName = "") override;
};


struct Occupied : public RoomStatus {

    string status = "Occupied";

    const string &getStatus() override { return status; };

    RoomStatusHolder onEvent(const Event &event, RoomName roomName = "") override;
};

struct Vacant : public RoomStatus {
    string status = "Vacant";

    const string &getStatus() override { return status; };

    RoomStatusHolder onEvent(const Event &event, RoomName roomName = "") override;
};

struct Repair : public RoomStatus {
    string status = "Repair";

    const string &getStatus() override { return status; };

    RoomStatusHolder onEvent(const Event &event, RoomName roomName = "") override;
};

