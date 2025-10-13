#include <queue>
#include <string>
#include <vector>

class Node{
    public:

    Node* left;
    Node* right;
    Node* father;
    std::pair<std::string, size_t> pair;
    std::string symbol;
    size_t value;

    Node() {};
    Node(Node* n1, Node* n2, Node* n3, std::string s, size_t f){
        this->father = n3;
        this->left = n1;
        this->right = n2;
        this->symbol = s;
        this->value = f;
    }
};

class Tree{
    public: 
    Node* main_node = nullptr;

    struct CompareByKey {
        bool operator()(const Node* a, const Node* b) const {
            return a->value > b->value; 
        }
    };

    std::priority_queue<Node*, std::vector<Node*>, CompareByKey> pq;

    Node* generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey>);
};
