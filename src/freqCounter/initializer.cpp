#include "initializer.hpp"
#include <filesystem>
#include <iostream>
#include <ostream>

void initializer::check_amount_of_inputs(int argc) {
    if (argc > 2) {
        std::cerr << "Please type the name of just one .cpp file!\n";
        ready_to_read = false;
    }
    else if (argc < 2){
        std::cerr << "Please type the name of your .cpp file!\n";
        ready_to_read = false;
    }
}

void initializer::check_extension(char *argv[]){
    std::string extension = std::filesystem::path(argv[1]).extension().string();
    if (extension == ".cpp"){ready_to_read = true;}
    else {std::cerr << "Please verify the extension of your file!\n";}
}