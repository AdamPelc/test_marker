#pragma once

#include "trick/test_checkpoint/configuration.hpp"

namespace trick::test_checkpoint
{
    void add_checkpoint(std::ostream& ostream);
    void add_checkpoint(const std::filesystem::path& path);

    //template<typename T, typename... Args>
    //void add_checkpoint(T&& param, Args&&... args) {
    //    poc_add_checkpoint(param);
    //    poc_add_checkpoint(args...);
    //}
}
