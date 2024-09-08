#include "trick/test_checkpoint/checkpoint.hpp"

#include <string>
#include <fstream>
#include <gtest/gtest.h>

using namespace std::literals::string_literals;

static std::string get_actual_filecontent(const std::filesystem::path& file) {
    auto reader = std::ifstream(file, std::ios::in);
    auto buffer = std::stringstream();
    reader >> buffer.rdbuf();
    return buffer.str();
}

TEST(checkpoint, save_checkpoint_to_ostream) {
    // arrange
    auto buffer = std::stringstream();

    // act
    trick::test_checkpoint::add_checkpoint(buffer);

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_ostream)\n"s, buffer.str());
}

TEST(checkpoint, save_checkpoint_to_file) {
    // arrange
    const auto file_path = "./checkpoints.txt"s;

    // act
    trick::test_checkpoint::add_checkpoint(file_path);
    const auto actual = get_actual_filecontent(file_path);

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_file)\n"s, actual);
}

TEST(checkpoint, save_multiple_checkpoints_to_file) {
    // arrange
    const auto file_path = "./checkpoint_save_multiple_checkpoints_to_file.txt"s;

    // act
    trick::test_checkpoint::add_checkpoint(file_path);
    trick::test_checkpoint::add_checkpoint(file_path);
    const auto actual = get_actual_filecontent(file_path);

    // assert
    auto expected = std::string();
    expected += "GTEST(checkpoint, save_multiple_checkpoints_to_file)\n";
    expected += "GTEST(checkpoint, save_multiple_checkpoints_to_file)\n";
    EXPECT_EQ(expected, actual);
}

TEST(checkpoint, save_checkpoint_to_multiple_locations) {
    // arrange
    const auto file_path = "./checkpoint_save_checkpoint_to_multiple_locations.txt";
    auto buffer = std::stringstream();

    // act
    trick::test_checkpoint::add_checkpoint(file_path, buffer);
    const auto actual = get_actual_filecontent(file_path);

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_locations)\n"s, actual);
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_locations)\n"s, buffer.str());
}

TEST(checkpoint, save_checkpoint_to_multiple_files) {
    // arrange
    const auto file_path_1 = "./checkpoint_save_checkpoint_to_multiple_files.txt";
    const auto file_path_2 = "./checkpoint_save_checkpoint_to_multiple_files_2.txt";

    // act
    trick::test_checkpoint::add_checkpoint(file_path_1, file_path_2);
    const auto actual_1 = get_actual_filecontent(file_path_1);
    const auto actual_2 = get_actual_filecontent(file_path_2);

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_files)\n"s, actual_1);
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_files)\n"s, actual_2);
}

TEST(checkpoint, save_checkpoint_to_multiple_buffers) {
    // arrange
    auto buffer_1 = std::stringstream();
    auto buffer_2 = std::stringstream();

    // act
    trick::test_checkpoint::add_checkpoint(buffer_1, buffer_2);

    // assert
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_buffers)\n"s, buffer_1.str());
    EXPECT_EQ("GTEST(checkpoint, save_checkpoint_to_multiple_buffers)\n"s, buffer_2.str());
}
