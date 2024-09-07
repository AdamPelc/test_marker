#include "trick/test_checkpoint/checkpoint.hpp"

#include <string>
#include <fstream>
#include <gtest/gtest.h>

using namespace std::literals::string_literals;

TEST(Checkpoint, SaveCheckpointToOstream) {
    std::stringstream stringstream;
    ASSERT_NO_THROW(trick::test_checkpoint::add_checkpoint(stringstream));

    EXPECT_EQ("GTEST(Checkpoint, SaveCheckpointToOstream)\n"s, stringstream.str());
}

TEST(Checkpoint, SaveCheckpointToFile) {
    // Arrange
    const std::string file_path = "./checkpoints.txt";

    // Act
    ASSERT_NO_THROW(trick::test_checkpoint::add_checkpoint(file_path));
    std::ifstream reader(file_path, std::ios::in);
    std::stringstream actual;
    reader >> actual.rdbuf();

    // Assert
    EXPECT_EQ("GTEST(Checkpoint, SaveCheckpointToFile)\n"s, actual.str());
}
