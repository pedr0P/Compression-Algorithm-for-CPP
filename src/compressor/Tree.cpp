#include "Tree.hpp"
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

}
