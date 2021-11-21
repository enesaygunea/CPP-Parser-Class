#include <iostream>
#include <sstream>
#include "file_parser.h"

int main()
{
    TestFileParser fileParser1{ "File1.test", "Test.txt" }; // create a new instance from TestFileParser base class
    fileParser1.parse(); // parse file contents
    const auto& fileContents = fileParser1.getContents(); //  load file contents to vector(Dynamic Array DS)

    for (const auto& item : fileContents)
    {
        std::istringstream item_str(item);
        std::string s;
        while (getline(item_str, s, ' ')) { // getline, invokes own operator bool function.
            std::cout << s << '\n';
        }
        std::cout << '\n';   
    }
}