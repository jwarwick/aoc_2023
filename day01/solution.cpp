#include "solution.hpp"

#include <doctest.h>
#include <iostream>


Solution::Solution(std::vector<std::string> input) : input(input) {
}

void Solution::part1()
{
  for (auto l : input) {
    std::cout << l << std::endl;
  }
  std::cout << "Part 1: " << std::endl;
}

void Solution::part2()
{
  std::cout << "Part 2: " << std::endl;
}

TEST_CASE("testing the factorial function") {
    CHECK(1 == 1);
    CHECK(0 == 1);
}

