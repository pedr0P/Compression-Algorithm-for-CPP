
#include <string>
#include <unordered_map>
#include <vector>

class freqCounter {
    public:
    std::vector<std::string> WordsTable{
        "#define",
        "#include",

        "int",
        "string",
        "char",
        "class",
        "struct",
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
        "break",
        "const",
        "push",
        "pop",
        "get",
        "set",
    };

    std::unordered_map<std::string, size_t> readFile(std::string);


    
};
