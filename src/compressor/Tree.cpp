#include "Tree.hpp"
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

Node* getNodeBySymbol(std::string symbol, Node* tree){
    if (tree->left){
        if (tree->left->symbol == symbol){ return tree->left; }
        else {return getNodeBySymbol(symbol, tree->left);}
    }
    else if (tree->right){
        if (tree->right->symbol == symbol){ return tree->right; }
        else {return  getNodeBySymbol(symbol, tree->right);}
    }

    return nullptr;

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

void Tree::compress(std::string filename, Node* root){
    std::vector<std::string> words;
    std::ifstream file;
    std::string line;
    //words.push_back("lararo");

    file.open(std::filesystem::path(filename));

    while (std::getline(file, line)){
        if (line.empty()){continue;}
        std::stringstream ss(line);
        std::string str;

        while (ss >> str){
            //words.push_back(str);
            //words.push_back(" ");
            
            std::cout << str;
        }
    }

    for (std::string s : words){
        //int : 101
        //main : tem que dividir

        Node* nd = getNodeBySymbol(s, root); 
        if (nd  != nullptr) {
            s = nd->code;
        }
        else
        {
            std::string tmp = "";
            for (char c : s){
                tmp += getNodeBySymbol(std::to_string(c), root)->code;
            }
            s = tmp;
        }

        std::cout << s;
    } 
    
    file.close();

    //std::ofstream outfile;
    //outfile.open("comprimido");

    //for (std::string s : words){
    //    outfile << s;
    //}

}
