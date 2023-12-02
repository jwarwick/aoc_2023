#include <vector>
#include <string>

class Solution {
  public:
    Solution(std::vector<std::string>);
    int part1();
    int part2();

    int rowValue(std::string row);
    int rowValue2(std::string row);
    std::string replaceWords(std::string row);
  private:
    std::vector<std::string> input;
};
