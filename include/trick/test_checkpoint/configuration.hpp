#pragma once

#include <ostream>
#include <filesystem>
#include <optional>

namespace trick::test_checkpoint {
    struct configuration {
        std::ostream* ostream = nullptr;
        std::optional<std::filesystem::path> path = {};
    };
}
