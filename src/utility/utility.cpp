#include "utility.hpp"
#include "test_data.hpp"

#define BOOST_STACKTRACE_LINK
#include <boost/regex.hpp>
#include <boost/stacktrace.hpp>

namespace trick::test_checkpoint::utility {
    test_data get_test_data() noexcept {
        const auto stacktrace = to_string(boost::stacktrace::stacktrace());
        const auto expression = boost::regex(R"(#\s(.*?)_(.*)_Test::TestBody\(\))");
        boost::match_results<std::string::const_iterator> what;
        constexpr boost::match_flag_type flags = boost::match_not_dot_newline;
        const auto start = std::begin(stacktrace);
        const auto end = std::end(stacktrace);
        while (::boost::regex_search(start, end, what, expression, flags)) {
            return test_data{
                .test_fixture_name = what[1].str(),
                .test_name = what[2].str()
            };
        }
        return {};
    }
}
