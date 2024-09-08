#include "trick/test_checkpoint/checkpoint.hpp"
#include "utility/utility.hpp"
#include "flag/is_new_file.hpp"

#include <fstream>
#include <unordered_map>

namespace  trick::test_checkpoint {
    static std::unordered_map<std::filesystem::path, flag::is_new_file> files_map;

    void add_checkpoint(std::ostream &ostream) {
        const auto [test_fixture_name, test_name] = utility::get_test_data();

        ostream << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
    }

    void add_checkpoint(const std::filesystem::path &path) {
        const auto [test_fixture_name, test_name] = utility::get_test_data();

        const auto& open_mode = [&path] {
            if(flag::is_new_file::True == files_map[path]) {
                files_map.at(path) = flag::is_new_file::False;
                return std::ios::out;
            }
            return std::ios::app;
        }();

        auto writer = std::ofstream(path, open_mode);
        writer << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
    }


}
