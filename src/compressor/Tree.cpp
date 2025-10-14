#include "Tree.hpp"
#include "../freqCounter/initializer.cpp"
#include "../freqCounter/freqCounter.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
// With help (but not copying) from: https://www.geeksforgeeks.org/dsa/huffman-coding-greedy-algo-3

Node* Tree::generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey> &pq){
    while (pq.size() >= 2) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* nd = new Node(left, right, "" , left->value + right->value);

        pq.push(nd);
    }
    Node* tree = pq.top();
    return tree;
}

Node* glob = nullptr;

void getNodeBySymbol(std::string symbol, Node* tree){
    if (symbol == tree->symbol) glob = tree;
    if (tree->left != nullptr) getNodeBySymbol(symbol, tree->left);
    if (tree->right != nullptr) getNodeBySymbol(symbol, tree->right);
}

void Tree::codifyTree(Node* root){
    if (root->left){
        root->left->code = root->code + "0";
        codifyTree(root->left);
    }
    if (root->right){
        root->right->code = root->code + "1";
        codifyTree(root->right);
    }
}

unsigned char to_bin(std::string str) {
    unsigned char res{0};
    for (int i{int(str.size()-1)}; i >= 0; --i) {
        char c = str[i];
        switch (c) {
            case('1'): {
                res = (res << 1) + 1;
                break;
            }
            case('0'): {
                res = res << 1;
                break;
            }
        }
    }
    return res;
}

void Tree::compress(std::string filename, Node* root){
    std::vector<std::string> words;
    std::ifstream file;
    std::string line;

    bool isOpen{false};

    file.open(std::filesystem::path(filename));

    while (std::getline(file, line)){
        words.clear();
        if (line.empty()){ continue; }

        std::string str;
        for (size_t i{0}; i < line.size(); ++i) {
            char c = line[i];
            if (c != ' ') {
                str += c;
            }
            else {
                if (!str.empty()) {
                    words.push_back(str);
                    str.clear();
                }
                words.push_back(" ");
                continue;
            }
            if (i == line.size()-1) {
                words.push_back(str);
                str.clear();
            }
        }

        for (size_t i{0}; i < words.size(); ++i){
            getNodeBySymbol(words[i], root); 
            if (glob  != nullptr) {
                words[i] = glob->code;
            }
            else {
                std::string tmp = "";
                for (char c : words[i]){

                    std::string s;
                    s.push_back(c);

                    getNodeBySymbol(s, root);
                    tmp += glob->code;
                }
                words[i] = tmp;
            }
            glob = nullptr;
        } 

        std::ofstream outfile;
        if (isOpen) {
            outfile.open("comprimido.tp", std::ios::app);
        }
        else {
            outfile.open("comprimido.tp");
            isOpen = true;
        }

        for (std::string s : words){
            outfile << to_bin(s);
        }
        outfile << '\n';
    }

    file.close();

}
void write_bits_to_file(std::string str, bool isOpen) {

}
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

int main(int argc, char* argv[]) {
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

    Node* p = tree->generateTree(tree->pq);
    tree->codifyTree(p);
    printTree(p);
    tree->compress(argv[1], p);
}
