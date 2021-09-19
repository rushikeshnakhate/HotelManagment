#pragma once


enum class Event {
    CheckIn,
    CheckOut,
    Cleaning,
    Repairing,
    RepairingCompleted,
    Enquiry
};


inline std::ostream &operator<<(std::ostream &os, const Event &event) {
    switch (event) {
        case Event::CheckIn:
            os << "CheckIn request";
            break;
        case Event::CheckOut:
            os << "CheckOut request";
            break;
        case Event::Cleaning:
            os << "Cleaning request";
            break;
        case Event::Repairing:
            os << "Repairing request";
            break;
        case Event::RepairingCompleted:
            os << "RepairingCompleted request";
            break;
        case Event::Enquiry:
            os << "Enquiry request";
            break;
    }
    return os;
}
