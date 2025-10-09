#include <iostream>
#include "initializer.cpp"
#include "freqCounter.cpp"

void printMap(const std::unordered_map<std::string, size_t>& mapa) {
    for (const auto& par : mapa) {
        std::cout << "Chave: " << par.first << ", Valor: " << par.second << std::endl;
    }
}

int main(int argc, char *argv[]) {
    initializer* init = new initializer();
    freqCounter* counter = new freqCounter();

    init->check_amount_of_inputs(argc);
    init->check_extension(argv);

    auto freqtable = counter->readFile(argv[1]);

    

    printMap(freqtable);

}
