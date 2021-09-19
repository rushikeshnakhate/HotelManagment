#include "gtest/gtest.h"
#include "../main/Database.h"

TEST(HotelInit, when_hotel_created_then_initial_status_is_available) {
    Database::init();
    auto rooms = all_of(Database::getHotelRegister().begin(), Database::getHotelRegister().end(),
                        [](const Room &room) {
                            Available available;
                            return (room.roomStatus->getStatus() == available.getStatus());
                        });
    EXPECT_TRUE(rooms);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}