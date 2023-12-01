add_library(doctest OBJECT test_main.cpp)
target_include_directories (doctest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
