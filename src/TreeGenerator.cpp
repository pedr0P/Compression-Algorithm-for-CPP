#include "TreeGenerator.hpp"

void Tree::generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey> pq, Node* nd){
    
    while (!pq.empty()){
        if (nd->left != nullptr && nd->right != nullptr){ 
            Node* nd1 = new Node();
        }
        //nd->symbol = pq.top().;
        //nd->value = pq.top().second;
        pq.pop();


    }

}