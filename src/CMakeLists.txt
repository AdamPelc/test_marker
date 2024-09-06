target_sources(test_checkpoint
    PRIVATE
    checkpoint.cpp
)
target_include_directories(test_checkpoint PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(utility)
