#pragma once

#include <type_traits>
#include <filesystem>

namespace trick::test_checkpoint
{
    void add_checkpoint(std::ostream& ostream);
    void add_checkpoint(const std::filesystem::path& path);

    template<typename T>
    concept checkpoint_storage = std::is_convertible_v<T&, std::ostream&> || std::is_convertible_v<T, std::filesystem::path>;

    template<typename>
    inline constexpr bool dependent_false_v = false;

    template<checkpoint_storage T, checkpoint_storage... Args>
    void add_checkpoint(T& param, Args&... args) {
        if constexpr (std::is_convertible_v<T&, std::ostream&>) {
            add_checkpoint(static_cast<std::ostream&>(param));
        }
        else if constexpr (std::is_convertible_v<T, std::filesystem::path>) {
            add_checkpoint(std::filesystem::path(param));
        } else {
            static_assert(dependent_false_v<T>, R"("Must meet "checkpoint_storage" concept requirements.)");
        }

        if constexpr(sizeof...(Args) != 0) {
            add_checkpoint(args...);
        }
    }
}
