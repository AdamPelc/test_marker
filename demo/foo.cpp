#include "foo.hpp"

#include <trick/test_checkpoint/checkpoint.hpp>
#include <iostream>

void foo() {
    std::cout << "foo" << std::endl;
    trick::test_checkpoint::add_checkpoint("./checkpoints.txt", std::cout);
}

void bar() {
    foo();
}
