#include "TestStateMachine.h"
#include "../main/Reception.h"

TEST_F(TestStateMachine, only_available_room_can_booked) {
    EXPECT_TRUE(Reception::process(Event::CheckIn, "1A"));
    EXPECT_FALSE(Reception::process(Event::CheckIn, "1A"));
}

TEST_F(TestStateMachine, assigned_available_room_become_occupied) {
    Occupied occupied;
    EXPECT_EQ(Database::findRoomByName("1A")->roomStatus->getStatus(), occupied.getStatus());
}

TEST_F(TestStateMachine, checkedout_room_become_vaccant) {
    Vacant vacant;
    Reception::process(Event::CheckOut, "1A");
    EXPECT_EQ(Database::findRoomByName("1A")->roomStatus->getStatus(), vacant.getStatus());
}

TEST_F(TestStateMachine, vaccant_room_after_cleaning_become_availabe) {
    Available available;
    Reception::process(Event::Cleaning, "1A");
    EXPECT_EQ(Database::findRoomByName("1A")->roomStatus->getStatus(), available.getStatus());
}

TEST_F(TestStateMachine, vaccant_room_can_be_repaired) {
    Repair repair;
    Reception::process(Event::CheckIn);
    Reception::process(Event::CheckOut, "1A");
    Reception::process(Event::Repairing, "1A");
    EXPECT_EQ(Database::findRoomByName("1A")->roomStatus->getStatus(), repair.getStatus());
}

TEST_F(TestStateMachine, once_room_is_repaired_become_vacant) {
    Vacant vacant;
    Reception::process(Event::CheckIn);
    Reception::process(Event::CheckOut, "1A");
    Reception::process(Event::Repairing, "1A");
    Reception::process(Event::RepairingCompleted, "1A");
    EXPECT_EQ(Database::findRoomByName("1A")->roomStatus->getStatus(), vacant.getStatus());
}

//room under repair can only be vacant
//which also means RepairingCompleted can be only be done for under room under Repairing
TEST_F(TestStateMachine, room_under_repair_can_only_be_vacant) {
    Vacant vacant;
    Reception::process(Event::CheckIn);
    Reception::process(Event::CheckOut, "1A");
    Reception::process(Event::Repairing, "1A");
    EXPECT_FALSE(Reception::process(Event::CheckOut, "1A"));
    EXPECT_FALSE(Reception::process(Event::Cleaning, "1A"));
    EXPECT_FALSE(Reception::process(Event::CheckIn, "1A"));
}