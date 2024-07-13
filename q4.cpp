#include <iostream>
#include <queue>
#include <string> 
#include <sstream>

#define MARKER -1

struct Node {
	int value;
	struct Node *left, *right;
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~Node() {
        delete left;
        delete right;
    }
};

class BinaryTree {
public:
    Node *root;
    BinaryTree() {
        this->root = nullptr;
    }
    ~BinaryTree() {
        delete root;
    }

    void PrintPreOrderTraversal() const {
        PrintPreOrderTraversalUtil(this->root);
        std::cout << "\n";
    }

    std::string Serialize() const {
        return SerializeUtil(this->root);
    }

    void Deserialize(const std::string &str) {
        std::stringstream ss;
        ss << str;
        std::queue<std::string> tokens;
        std::string token;
        while(ss >> token) {
            tokens.emplace(token);
        }
        DeserializeUtil(this->root, tokens);
    }

private:
    void PrintPreOrderTraversalUtil(const Node *node) const {
        if(node == nullptr) {
            std::cout << "NULL, ";
            return;
        }
        std::cout << node->value << ", ";
        PrintPreOrderTraversalUtil(node->left);
        PrintPreOrderTraversalUtil(node->right);
    }

    std::string SerializeUtil(const Node *node) const {
        if(node == nullptr) {
            return "N ";
        } else {
            std::string value = std::to_string(node->value) + " ";
            value += SerializeUtil(node->left);
            value += SerializeUtil(node->right);
            return value;
        }
    }

    void DeserializeUtil(Node *&node, std::queue<std::string> &tokens) {
        std::string value = tokens.front();
        tokens.pop();
        if(value == "N" || value == " " || value == "") {
            return;
        } else {
            node = new Node(std::stoi(value));
            DeserializeUtil(node->left, tokens);
            DeserializeUtil(node->right, tokens);
        }
    }
};





int main() {
    /*
     *           11
     *           /\
     *          /  \
     *         2    12
     *        /\     \
     *      21  2    -23
     *                /\
     *               /  \
     *              36   4
    */

    BinaryTree tree;
    tree.root = new Node(11);
	tree.root->left = new Node(2);
	tree.root->right = new Node(12);
	tree.root->left->left = new Node(21);
	tree.root->left->right = new Node(2);
	tree.root->right->right = new Node(-23);
	tree.root->right->right->left = new Node(36);
	tree.root->right->right->right = new Node(4);

    std::cout << "Tree 1 pre-order traversal:\n";
	tree.PrintPreOrderTraversal();
    std::string str = tree.Serialize();
    BinaryTree tree2;
    tree2.Deserialize(str);
    std::cout << "\nTree 2 pre-order traversal after deserializing from tree 1 serialized data:\n";
    tree2.PrintPreOrderTraversal();

	return 0;
}
