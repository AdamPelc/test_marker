#include "test_marker.h"

#define BOOST_STACKTRACE_LINK
#include <boost/regex.hpp>
#include <boost/stacktrace.hpp>

namespace trick {
    std::optional<std::pair<std::string, std::string>> get_test_name() noexcept {
        const auto stacktrace = to_string(boost::stacktrace::stacktrace());
        const boost::regex expression(R"(#\s(.*?)_(.*)_Test::TestBody\(\))");
        boost::match_results<std::string::const_iterator> what;
        constexpr boost::match_flag_type flags = boost::match_not_dot_newline;
        const auto start = std::begin(stacktrace);
        const auto end = std::end(stacktrace);
        while (::boost::regex_search(start, end, what, expression, flags)) {
            return std::make_pair(what[1].str(), what[2].str());
        }
        return std::nullopt;
    }
}
