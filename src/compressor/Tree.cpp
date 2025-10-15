#include "Tree.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

Node* glob = nullptr;

//generate tree recursivelly
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
    return tree; //return the root with all his children
}

void getNodeBySymbol(std::string symbol, Node* tree){
    if (symbol == tree->symbol) glob = tree;
    if (tree->left != nullptr) getNodeBySymbol(symbol, tree->left);
    if (tree->right != nullptr) getNodeBySymbol(symbol, tree->right);
}

//simulates a binary operation 
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

//insert the codes at all nodes
void Tree::codifyTree(Node* root){
    if (root->left){
        root->left->code = root->code + "0"; //if right, code with 0
        codifyTree(root->left);
    }
    if (root->right){
        root->right->code = root->code + "1"; //if left, code with 1
        codifyTree(root->right);
    }
}

//the compression function
void Tree::compress(std::string filename, Node* root){
    std::vector<std::string> words;
    std::ifstream file;
    std::string line;

    bool isOpen{false};

    file.open(std::filesystem::path(filename));

    //for every line of the code
    while (std::getline(file, line)){
        words.clear();
        if (!line.empty()){
            std::string str;

            //get all the words separated by space and put at words vector
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

            //scan the words vector
            for (size_t i{0}; i < words.size(); ++i){
                getNodeBySymbol(words[i], root); 
                if (glob  != nullptr) {    //if i find the symbol at the tree,
                    words[i] = glob->code; //turn the word into his code
                }
                else { //if i dont find the symbol at the tree
                    std::string tmp = "";
                    for (char c : words[i]){ //find the code of all the characters of the word.

                        std::string s;
                        s.push_back(c);

                        getNodeBySymbol(s, root);
                        tmp += glob->code;
                    }
                    words[i] = tmp;
                }
                glob = nullptr;
            } 
        }

        std::ofstream outfile;
        if (isOpen) {
            outfile.open("comprimido.tp", std::ios::app);
        }
        else {
            outfile.open("comprimido.tp");
            isOpen = true;
        }

        //this is the algorithm that actually compress the code
        std::string buffer;
        std::string tmp;
        for (std::string s : words){
            while(buffer.size() <= 8) {
                buffer += s; //increments the buffer with the code s
            }
            //to avoid memory problems, the buffer written in file must have 8 bits
            while (buffer.size() > 8) { 
                tmp = buffer[buffer.size()-1];
                buffer.pop_back();
            }
            std::cout << buffer << '\n';
            outfile << to_bin(buffer);
            std::reverse(tmp.begin(), tmp.end());
            buffer = tmp;
            tmp.clear();
        }
        outfile << '\n';

    }

    file.close();

}
