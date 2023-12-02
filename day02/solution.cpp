#include "solution.hpp"

#include <doctest.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <algorithm>

constexpr auto MAX_RED = 12;
constexpr auto MAX_GREEN = 13;
constexpr auto MAX_BLUE = 14;

struct Draw {
  int red{};
  int green{};
  int blue{};
};

class Game {
  public:
    Game(std::string row) {
      std::vector<std::string> g = splitString(row, ':');
      std::vector<std::string> num = splitString(g.front(), ' ');
      number = std::stoi(num.back());

      auto d = splitString(g.back(), ';');
      for (auto curr : d) {
        draws.emplace_back(parseDraw(curr));
      }
    }

    Draw parseDraw(std::string in) {
      Draw d{};
      auto colors = splitString(in, ',');
      for (auto i : colors) {
        auto value = std::regex_replace(i, std::regex("^ +| +$|( ) +"), "$1");
        auto values = splitString(value, ' ');
        auto count = std::stoi(values.front());
        if (values.back() == "red") {
          d.red = count;
        } else if (values.back() == "green") {
          d.green = count;
        } else if (values.back() == "blue") {
          d.blue = count;
        } else {
          std::cout << "Unknown color:" << values.back() << std::endl;
          assert("Failed to parse color");
        }

      }
      return d;
    }

    std::vector<std::string> splitString(std::string in, char sep) {
      std::vector<std::string> r;
      for (auto p = in.begin();; ++p) {
        auto q = p;
        p = std::find(p, in.end(), sep);
        r.emplace_back(q, p);
        if (p == in.end())
          return r;
      }
    }

    bool isValid() {
      for (auto d : draws) {
        if (d.red > MAX_RED || d.green > MAX_GREEN || d.blue > MAX_BLUE) {
          return false;
        }
      }
      return true;
    }

    int power() {
      int max_red{0};
      int max_green{0};
      int max_blue{0};
      for (auto d : draws) {
        max_red = std::max(max_red, d.red);
        max_green = std::max(max_green, d.green);
        max_blue = std::max(max_blue, d.blue);
      }
      return max_red * max_green * max_blue;
    }

    int number;
    std::vector<Draw> draws;
};

TEST_CASE("game") {
  auto v{"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
  Game g(v);
  CHECK(g.number == 1);
  CHECK(g.draws.size() == 3);
  CHECK(g.draws[0].red == 4);
  CHECK(g.draws[0].green == 0);
  CHECK(g.draws[0].blue == 3);
  CHECK(g.draws[1].red == 1);
  CHECK(g.draws[1].green == 2);
  CHECK(g.draws[1].blue == 6);
  CHECK(g.draws[2].red == 0);
  CHECK(g.draws[2].green == 2);
  CHECK(g.draws[2].blue == 0);
  CHECK(g.isValid() == true);
  CHECK(g.power() == 48);
}

Solution::Solution(std::vector<std::string> input) : input(input) {
}

int Solution::part1()
{
  std::vector<Game> games;
  for (auto s : input) {
    games.emplace_back(Game(s));
  }
  int total{0};
  for (auto g: games) {
    if (g.isValid()) {
      total += g.number;
    }
  }
  std::cout << "Part 1: " << total << std::endl;
  return total;
}

TEST_CASE("part 1 example") {
  std::vector<std::string> v{
    "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
      "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
      "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
      "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
      "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
  };
  Solution s(v);
  CHECK(s.part1() == 8);
}

int Solution::part2()
{
  std::vector<Game> games;
  for (auto s : input) {
    games.emplace_back(Game(s));
  }
  int total{0};
  for (auto g: games) {
    total += g.power();
  }
  std::cout << "Part 2: " << total << std::endl;
  return total;
}

TEST_CASE("part 2 example") {
  std::vector<std::string> v{
    "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
      "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
      "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
      "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
      "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
  };
  Solution s(v);
  CHECK(s.part2() == 2286);
}
