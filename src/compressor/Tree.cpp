#include "Tree.hpp"

Node* Tree::generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey> pq){
    Node* nd = new Node();
    nd = pq.top();
    pq.pop();
    Node* father = new Node();
    nd->father = father;
    father->value = nd->value;
    father->right = nd;

    while (!pq.empty()) {
        father->left = pq.top();
        pq.pop();

        father->value += father->left->value;
        father->father = new Node();

        father->father->right = father;
        father = father->father;
    }
    return nd;
}

void Tree::codifyTree(Node* root){
    if (root->left){
        root->left->code = root->code + "0";
    }
    if (root->right){
        root->right->code = root->code + "1";
        codifyTree(root->right);
    }
}

void Tree::compress(std::string filename, Node* root){
    
}
