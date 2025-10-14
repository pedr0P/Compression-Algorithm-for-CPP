#include <queue>
#include <string>
#include <vector>

class Node{
    public:
    Node *left, *right;

    std::string symbol{""};
    std::string code;
    int value{-1};
    
    Node() {};
    Node(Node* n1, Node* n2, std::string s, int f){
        this->left = n1;
        this->right = n2;
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

    Node* generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey>&);

    void codifyTree(Node*);

    void compress(std::string, Node*);
};
