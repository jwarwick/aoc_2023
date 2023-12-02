#include "solution.hpp"

#include <doctest.h>
#include <iostream>


Solution::Solution(std::vector<std::string> input) : input(input) {
}

int Solution::part1()
{
  int total{0};
  std::cout << "Part 1: " << total << std::endl;
  return total;
}

TEST_CASE("part 1 row value") {
  std::vector<std::string> v{"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
  Solution s(v);
  CHECK(s.part1() == 142);
}

int Solution::part2()
{
  int total{0};
  return total;
}
