#include <queue>
#include <string>
#include <utility>
#include <vector>

class Node{
    public:
    Node* left;
    Node* right;
    Node* father;
    std::pair<std::string, size_t> pair;
    std::string symbol;

    std::string code;
    size_t value;
    
    Node() {};
    Node(Node* n1, Node* n2, Node* n3, std::string s, size_t f){
        this->left = n1;
        this->right = n2;
        this->father = n3;
        this->symbol = s;
        this->value = f;
        this->code = "";
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

    void generateTree(std::priority_queue<Node*, std::vector<Node*>, CompareByKey>, Node*);

    void codifyTree(Node*);

    void compress(std::string, Node*);
};
