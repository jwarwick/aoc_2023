#include "inputfile.hpp"

#include <fstream>

InputFile::InputFile(std::string input_path) : path(input_path)
{
}

std::vector<std::string> InputFile::getContentAsStrings()
{
  std::ifstream file(path);
  std::vector<std::string> content;

  if(!file.is_open()) {
    throw std::runtime_error("Failed to open " + path);
  }

  std::string line;
  while(std::getline(file, line)) {
      content.emplace_back(line);
  }
  return content;
}

