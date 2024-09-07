#pragma once

#include <ostream>
#include <filesystem>
#include <optional>

namespace trick::test_checkpoint {
    struct configuration {
        std::ostream* ostream = nullptr;
        std::optional<std::filesystem::path> path = {};
    };

    template <typename T>
    struct poc_config {
        T m_t;
    };
}
