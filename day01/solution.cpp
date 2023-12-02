#include "solution.hpp"

#include <doctest.h>
#include <iostream>
#include <cassert>
#include <regex>
#include <string>


Solution::Solution(std::vector<std::string> input) : input(input) {
}

int Solution::part1()
{
  int total{0};
  for (auto l : input) {
    total += rowValue(l);
  }
  std::cout << "Part 1: " << total << std::endl;
  return total;
}

int Solution::rowValue(std::string row) {
  std::vector<int> digits;
  for (auto c : row) {
    if (isdigit(c)) {
      digits.emplace_back(c - '0');
    }
  }
  assert(digits.size() >= 1);
  return (10 * digits.front()) + digits.back();
}

TEST_CASE("part 1 row value") {
  std::vector<std::string> v{"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
  Solution s(v);
  CHECK(s.rowValue("1abc2") == 12);
  CHECK(s.rowValue("pqr3stu8vwx") == 38);
  CHECK(s.rowValue("a1b2c3d4e5f") == 15);
  CHECK(s.rowValue("treb7uchet") == 77);

  CHECK(s.part1() == 142);
}

int Solution::part2()
{
  int total{0};
  for (auto l : input) {
    total += rowValue2(l);
  }
  std::cout << "Part 2: " << total << std::endl;
  assert(total < 53551);
  return total;
}

std::string Solution::replaceWords(std::string row) {
  auto one = std::regex_replace(row, std::regex("one"), "1e");
  auto two = std::regex_replace(one, std::regex("two"), "2o");
  auto three = std::regex_replace(two, std::regex("three"), "3e");
  auto four = std::regex_replace(three, std::regex("four"), "4r");
  auto five = std::regex_replace(four, std::regex("five"), "5e");
  auto six = std::regex_replace(five, std::regex("six"), "6x");
  auto seven = std::regex_replace(six, std::regex("seven"), "7n");
  auto eight = std::regex_replace(seven, std::regex("eight"), "8t");
  auto nine = std::regex_replace(eight, std::regex("nine"), "9e");
  return nine;
}


int Solution::rowValue2(std::string row) {
  auto len = row.length();
  std::string curr{""};
  for (int idx = 0; idx < len; idx++) {
    auto next = row.substr(idx, 1);
    auto sub = curr.append(next);
    curr = replaceWords(sub);
  }
  auto v = rowValue(curr);
  return v;
}

TEST_CASE("part 2 row value") {
  std::vector<std::string> v{
    "two1nine",
      "eightwothree",
      "abcone2threexyz",
      "xtwone3four",
      "4nineeightseven2",
      "zoneight234",
      "7pqrstsixteen"};
  Solution s(v);
  CHECK(s.rowValue2("two1nine") == 29);
  CHECK(s.rowValue2("eightwothree") == 83);
  CHECK(s.rowValue2("abcone2threexyz") == 13);
  CHECK(s.rowValue2("xtwone3four") == 24);
  CHECK(s.rowValue2("4nineeightseven2") == 42);
  CHECK(s.rowValue2("zoneight234") == 14);
  CHECK(s.rowValue2("7pqrstsixteen") == 76);

  CHECK(s.rowValue2("182twoone") == 11);
  CHECK(s.rowValue2("5twonine") == 59);
  CHECK(s.rowValue2("5twonineeight3onefive") == 55);
  CHECK(s.rowValue2("one") == 11);
  CHECK(s.rowValue2("twone") == 21);
  CHECK(s.rowValue2("oneight") == 18);
  CHECK(s.rowValue2("fiveight") == 58);
  CHECK(s.rowValue2("eightwo") == 82);
  CHECK(s.rowValue2("eighthree") == 83);
  CHECK(s.rowValue2("sevenine") == 79);
  CHECK(s.rowValue2("nineight") == 98);
  CHECK(s.rowValue2("nineighthree") == 93);

  CHECK(s.rowValue2("1abc2") == 12);
  CHECK(s.rowValue2("pqr3stu8vwx") == 38);
  CHECK(s.rowValue2("a1b2c3d4e5f") == 15);
  CHECK(s.rowValue2("treb7uchet") == 77);

  CHECK(s.part2() == 281);
}
