#include "Tree.hpp"

// void Tree::generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey> pq, Node* nd){
//
//     while (!pq.empty()){
//         if (nd->left != nullptr && nd->right != nullptr){ 
//             Node* nd1 = new Node();
//         }
//         //nd->symbol = pq.top().;
//         //nd->value = pq.top().second;
//         pq.pop();
//
//
//     }
//
// }

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