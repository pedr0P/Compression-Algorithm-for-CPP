#include "initializer.hpp"
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