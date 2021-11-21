#include <iostream>
#include <fstream>
#include "file_parser.h"

TestFileParser::TestFileParser(std::string filePath, std::string destPath) : filepath(filePath), outputPath(destPath) {}
TestFileParser::~TestFileParser() {}

void TestFileParser::parse()
{
    std::ifstream input_file(filepath);
    std::ofstream output_file(outputPath);

    if (!input_file.is_open()) {
        std::cout << "Error, file could not be opened";
    }
    else {
        while (getline(input_file, line, ';')) {
            line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

            size_t start_pos = 0;
            size_t pos = 0;
            auto iter_beg = line.begin();
            while (iter_beg != line.end()) {

                pos = line.find('|', pos);
                auto word = line.substr(start_pos, (pos - start_pos));
                start_pos += word.size() + 1;

                if (pos != 0) {
                    output_file << word;
                    output_file << ' ';
                }

                pos = start_pos + 1;
                if (pos == line.size() + 2) {  // Prevent Iterator Invalidation   
                    iter_beg += word.size();
                    output_file << '\n';
                }
                else
                    iter_beg += word.size() + 1;
            }
        }
    }
}

std::vector<std::string> TestFileParser::getContents(void)
{
    std::ifstream infs("Test.txt");
    std::string line;
    while (getline(infs, line)) {
        parsedContainer.push_back(line);
    }

    return parsedContainer;
}
