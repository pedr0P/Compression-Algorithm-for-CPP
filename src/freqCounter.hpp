
#include <string>
#include <unordered_map>
#include <vector>

class freqCounter {
    public:
    std::vector<std::string> WordsTable{
        "int",
        "string",
        "char",
        "vector",
        "array",
        "bool",
        "auto",
        "void",

         "if",
         "else",
        "switch",
        "case",
        "for",
        "while",
        "do",

        "return",
        "include",
        "break",
        "const",
        "push",
        "pop",
        "get",
        "set",
    };

    std::vector<std::string> lineParser(std::string);

    std::unordered_map<std::string, size_t> readFile(std::string);


    
};