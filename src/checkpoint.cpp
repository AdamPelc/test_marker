#include "trick/test_checkpoint/checkpoint.hpp"
#include "utility/utility.hpp"

#include <fstream>

namespace  trick::test_checkpoint {
    void add_checkpoint(const configuration& configuration) {
        const auto [test_fixture_name, test_name] = utility::get_test_data();

        if(configuration.ostream) {
            std::ostream& ostream = *configuration.ostream;
            ostream << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
        }

        if(configuration.path) {
            std::ofstream writer(configuration.path.value(), std::ios::out);
            writer << "GTEST(" << test_fixture_name << ", " << test_name << ")\n";
        }
    }

}
