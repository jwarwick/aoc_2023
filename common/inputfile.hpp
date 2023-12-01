#include <string>
#include <vector>

class InputFile 
{
public:
    InputFile(std::string input_path);
    std::vector<std::string> getContentAsStrings();
private:
    std::string path;
};
