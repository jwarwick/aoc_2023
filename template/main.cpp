#include <iostream>

#include "inputfile.hpp"
#include "solution.hpp"

using namespace std;

int main() {
  InputFile inputFile("./input.txt");
  auto input = inputFile.getContentAsStrings();
  Solution s(input);
  s.part1();
  s.part2();
}
