#include <iostream>

#include "../freqCounter/initializer.hpp"
#include "../freqCounter/freqCounter.hpp"
#include "Tree.hpp"

void printMap(const std::unordered_map<std::string, size_t>& mapa) {
    for (const auto& par : mapa) {
        std::cout << "Chave: " << par.first << ", Valor: " << par.second << std::endl;
    }
}

int main(int argc, char *argv[]) {
    initializer* init = new initializer();
    freqCounter* counter = new freqCounter();
    Tree* tree = new Tree();



    init->check_amount_of_inputs(argc);
    init->check_extension(argv);

    auto freqtable = counter->readFile(argv[1]);

    //testing things
    printMap(freqtable);

    std::cout << "\n AGORA TESTANDO A PRIORITY QUEUE: \n";


    // adding everything at priority list
    for (const auto& par : freqtable) {
        tree->pq.push(new Node(nullptr, nullptr, nullptr, par.first, par.second));
    }

    while (!tree->pq.empty()) {
        const auto& topo = tree->pq.top();
        std::cout << "Chave: " << topo->symbol << ", Valor: " << topo->value << std::endl;
        tree->pq.pop();
    }
    

}
