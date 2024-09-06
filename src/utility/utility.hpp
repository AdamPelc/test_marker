#pragma once

#include <optional>
#include <utility>
#include <string>

namespace trick::test_checkpoint::utility {
  [[nodiscard]] std::optional<std::pair<std::string, std::string>> get_test_name() noexcept;
}
