#include <iostream>
#include "../freqCounter/initializer.cpp"
#include "../freqCounter/freqCounter.cpp"
#include "Tree.cpp"


void printTree(Node* node, const std::string& prefix = "", bool isLeft = true) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );

        // printing
        std::cout << node->symbol << "(" << node->value << ")";
        if (!node->code.empty()) {
            std::cout << " Código: " << node->code;
        }
        std::cout << std::endl;

        // recursive step
        printTree(node->left, prefix + (isLeft ? "│   " : "    "), true);
        printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}
// aux function
void printTreeFromRoot(Node* root) {
    std::cout << "Árvore:" << std::endl;
    printTree(root);
}

int main(int argc, char *argv[]) {
    initializer* init = new initializer();
    freqCounter* counter = new freqCounter();
    Tree* tree = new Tree();

    init->check_amount_of_inputs(argc);
    init->check_extension(argv);

    auto freqtable = counter->readFile(argv[1]);

    // adding everything at priority_queue
    for (const auto& par : freqtable) {
        tree->pq.push(new Node(nullptr, nullptr, par.first, par.second));
    }

    // Tests:
    //printing the priority_queue
    // while (!tree->pq.empty()) {
    //     const auto& topo = tree->pq.top();
    //     std::cout << "Chave: " << topo->symbol << ", Valor: " << topo->value << std::endl;
    //     tree->pq.pop();
    // }
    
    // Node* p = tree->generateTree(tree->pq);
    // tree->codifyTree(p);
    // printTreeFromRoot(p);
}
