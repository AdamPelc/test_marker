target_sources(test_checkpoint
    PRIVATE
    checkpoint.cpp
)
target_include_directories(test_checkpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(test_checkpoint.test
    PRIVATE
    checkpoint.test.cpp
)

add_subdirectory(utility)
