#pragma once

#include "gtest/gtest.h"
#include "../main/Database.h"

class TestDatabase : public ::testing::Test {
    void SetUp() override {
        Database::init();
    }
};
