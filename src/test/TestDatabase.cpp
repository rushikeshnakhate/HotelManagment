#include "TestDatabase.h"
#include <vector>

TEST_F(TestDatabase, validate_room_name_sequence) {
    std::vector<RoomName> expectedRoomSequence{"1A", "1B", "1C", "1D", "1E",
                                               "2E", "2D", "2C", "2B", "2A",
                                               "3A", "3B", "3C", "3D", "3E",
                                               "4E", "4D", "4C", "4B", "4A"};
    std::vector<RoomName> actualRoomSequence;
    for_each(Database::getHotelRegister().begin(), Database::getHotelRegister().end(),
             [&](const Room &room) {
                 actualRoomSequence.push_back(room.roomName);
             });
    EXPECT_EQ(expectedRoomSequence, actualRoomSequence);
}