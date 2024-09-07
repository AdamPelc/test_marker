#include "trick/test_checkpoint/checkpoint.hpp"
#include "utility/utility.hpp"

#include <fstream>

namespace  trick::test_checkpoint {
    void add_checkpoint(std::ostream &ostream) {
        const auto [test_fixture_name, test_name] = utility::get_test_data();

        ostream << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
    }

    void add_checkpoint(const std::filesystem::path &path) {
        const auto [test_fixture_name, test_name] = utility::get_test_data();

        std::ofstream writer(path, std::ios::out);
        writer << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
    }


}
