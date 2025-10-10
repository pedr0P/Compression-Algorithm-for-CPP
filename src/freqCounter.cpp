#include <filesystem>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include "freqCounter.hpp"

std::unordered_map<std::string, size_t> freqCounter::readFile(std::string filename){

    std::unordered_map<std::string, size_t> freqTable;
    std::ifstream file;
    std::string line;

    file.open(std::filesystem::path(filename));
    if (!file.is_open()) {std::cerr << "Error: Cannot open the file!" << std::endl;}

    while (std::getline(file, line)){
        if (line.empty()){continue;}

        for (std::string s : WordsTable){
            size_t indexOfS = line.find(s);
            while (indexOfS != std::string::npos){
                line.erase(indexOfS, s.length());
                freqTable[s] += 1;
                std::cout << line << std::endl;
                indexOfS = line.find(s);
            }
        }
        for (char c : line){
            freqTable[std::string(1, c)] += 1;
        }
    }

    file.close();


    return freqTable;
};

