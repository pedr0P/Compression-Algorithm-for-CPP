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
    printTree(root, "", false);
}

int main(int argc, char *argv[]) {
    initializer* init = new initializer();
    freqCounter* counter = new freqCounter();
    Tree* tree = new Tree();

    init->check_amount_of_inputs(argc);
    init->check_extension(argv);

    auto freqtable = counter->readFile(argv[1]);

    /*
    //testing things

    std::cout << "\nTESTANDO A PRIORITY QUEUE:\n\n";

    // adding everything at priority_queue
    for (const auto& par : freqtable) {
        tree->pq.push(new Node(nullptr, nullptr, nullptr, par.first, par.second));
    }
    //printing the priority_queue
    while (!tree->pq.empty()) {
        const auto& topo = tree->pq.top();
        std::cout << "Chave: " << topo->symbol << ", Valor: " << topo->value << std::endl;
        tree->pq.pop();
    }
    
    //creating a tree that will be created with the treeGenerator function. (this is provisory)
    Node* nodeA = new Node(nullptr, nullptr, nullptr, "A", 10);
    Node* nodeB = new Node(nullptr, nullptr, nullptr, "B", 6);
    Node* nodeC = new Node(nullptr, nullptr, nullptr, "C", 5);
    Node* nodeD = new Node(nullptr, nullptr, nullptr, "D", 4);
    Node* nodeE = new Node(nullptr, nullptr, nullptr, "E", 1);

    Node* sub1 = new Node(nodeD, nodeE,nullptr, "", nodeD->value + nodeE->value);
    Node* sub2 = new Node(nodeC, sub1, nullptr, "", nodeC->value + sub1->value);
    Node* sub3 = new Node(nodeB, sub2, nullptr, "", nodeB->value + sub2->value);
    Node* raiz = new Node(nodeA, sub3, nullptr, "", nodeA->value + sub3->value);

    tree->codifyTree(raiz);

    printTreeFromRoot(raiz);
    */
}
