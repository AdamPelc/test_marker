#include <gtest/gtest.h>
#include <iostream>
#define BOOST_STACKTRACE_LINK
#include <boost/stacktrace.hpp>
#include <boost/regex.hpp>

TEST(TestName, TC0001_TestCaseName) {
    const auto stacktrace = to_string(boost::stacktrace::stacktrace());

    {
        boost::regex expression_testname(R"(#\s(.*?)_(.*)_Test::TestBody\(\))");
        boost::match_results<std::string::const_iterator> what;
        boost::match_flag_type flags = boost::match_default;
        auto start = std::begin(stacktrace);
        while (boost::regex_search(start, std::end(stacktrace), what, expression_testname, flags)) {
            std::cout << "Test name: " << what[1] << "\n";
            std::cout << "Test case name: " << what[2] << "\n";
            // update search position:
            start = what[0].second;
            // update flags:
            flags |= boost::match_prev_avail;
            flags |= boost::match_not_bob;
        }
    }
    {
        boost::regex expression_testcase(R"(#\s.*?_(.*)_Test::TestBody\(\))");
        boost::match_results<std::string::const_iterator> what;
        boost::match_flag_type flags = boost::match_default;
        auto start = std::begin(stacktrace);
        while (boost::regex_search(start, std::end(stacktrace), what, expression_testcase, flags)) {
            std::cout << "Test case: " << what[1] << "\n";
            // update search position:
            start = what[0].second;
            // update flags:
            flags |= boost::match_prev_avail;
            flags |= boost::match_not_bob;
        }
    }

    std::cout << stacktrace << "\n";
    std::cout << "TC0001\n";
}
