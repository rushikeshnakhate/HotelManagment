#pragma once

#include "gtest/gtest.h"
#include "../main/Database.h"

class TestStateMachine : public ::testing::Test {
    void SetUp() override {
        Database::init();
    }
};

