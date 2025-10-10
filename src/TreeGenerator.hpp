
#include <queue>
#include <string>
#include <utility>
#include <vector>

class Node{
    public:

    Node* left = new Node();
    Node* right = new Node();
    Node* father = new Node();
    std::pair<std::string, size_t> pair;
    std::string symbol;
    size_t value;

    Node(){};
    Node(Node* n1, Node* n2, Node* n3, std::string s, size_t f){
        this->left = n1;
        this->right = n2;
        this->father = n3;
        this->symbol = s;
        this->value = f;
    }
};

class Tree{
    public: 

    struct CompareByKey {
        bool operator()(const Node* a, const Node* b) const {
            return a->value > b->value; 
        }
    };

    std::priority_queue<Node*, std::vector<Node*>, CompareByKey> pq;

    void generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey>, Node*);

    Tree();
};