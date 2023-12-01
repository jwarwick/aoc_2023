set(DAY "day11")

add_executable("${DAY}" main.cpp solution.cpp)
target_link_libraries("${DAY}" LINK_PUBLIC common)
target_compile_options("${DAY}" PUBLIC "-DDOCTEST_CONFIG_DISABLE")
target_include_directories("${DAY}" PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../doctest>")

enable_testing()
add_executable("${DAY}_test" solution.cpp)
target_link_libraries("${DAY}_test" LINK_PUBLIC doctest common)
add_test(NAME "${DAY}_test" COMMAND "${DAY}_test")
