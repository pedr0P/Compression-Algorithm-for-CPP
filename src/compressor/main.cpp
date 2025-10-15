#include <iostream>
#include "../freqCounter/initializer.cpp"
#include "../freqCounter/freqCounter.cpp"
#include "Tree.cpp"

//auxiliary function to print the tree
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

    auto freqtable = counter->readFile(argv[1]);

    //adding everything at priority_queue
    for (const auto& par : freqtable) {
        tree->pq.push(new Node(nullptr, nullptr, par.first, par.second));
    }

    //generating the tree
    Node* p = tree->generateTree(tree->pq);

    //putting the codes on the nodes
    tree->codifyTree(p);

    //compress algorithm
    tree->compress(argv[1], p);

}
