#include "TreeGenerator.hpp"
#include <iostream>

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
