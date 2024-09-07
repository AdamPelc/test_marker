#include "trick/test_checkpoint/checkpoint.hpp"

#include <string>
#include <fstream>
#include <gtest/gtest.h>

using namespace std::literals::string_literals;

TEST(checkpoint, save_checkpoint_to_ostream) {
    std::stringstream stringstream;
    ASSERT_NO_THROW(trick::test_checkpoint::add_checkpoint(stringstream));

    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_ostream)\n"s, stringstream.str());
}

TEST(checkpoint, save_checkpoint_to_file) {
    // Arrange
    const auto file_path = "./checkpoints.txt"s;

    // act
    ASSERT_NO_THROW(trick::test_checkpoint::add_checkpoint(file_path));
    std::ifstream reader(file_path, std::ios::in);
    std::stringstream actual;
    reader >> actual.rdbuf();

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_file)\n"s, actual.str());
}

TEST(checkpoint, save_checkpoint_to_multiple_locations) {
    // arrange
    const auto file_path = "./checkpoint_save_checkpoint_to_multiple_locations.txt";
    auto buffer = std::stringstream();

    // act
    trick::test_checkpoint::add_checkpoint(file_path, buffer);
    std::ifstream reader(file_path, std::ios::in);
    std::stringstream actual;
    reader >> actual.rdbuf();

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_locations)\n"s, actual.str());
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_locations)\n"s, buffer.str());
}
