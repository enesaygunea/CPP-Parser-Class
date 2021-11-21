/*include guard*/
#ifndef FILE_PARSER_H
#define FILE_PARSER_H

/*Libraries*/
#include <string>
#include <vector>

class TestFileParser {
public:
	TestFileParser(std::string filePath, std::string destPath); // constructor
	virtual ~TestFileParser(); //Note: Base class dtor must be virtual dtor or non-virtual but protected.

	//methods
public:
	std::vector<std::string> getContents(void);
	virtual void parse(); // overridable virtual member function
private:
	std::string filepath{};
	std::string outputPath{};
	std::vector<std::string> parsedContainer;
	std::string line{};
};

#endif // !FILE_PARSER_H

