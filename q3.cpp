#include <iostream>
#include <utility>

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

    int FindMaxPathSum() const {
	    int res = INT_MIN;
	    FindMaxPathSumUtil(this->root, res);
	    return res;
    }

private:
    int FindMaxPathSumUtil(const Node* node, int& res) const {
	    if (node == nullptr) {
    		return 0;
        }

	    int lSum = FindMaxPathSumUtil(node->left, res);
	    int rSum = FindMaxPathSumUtil(node->right, res);

	    int maxSingle = std::max(std::max(lSum, rSum) + node->value, node->value);
	    int maxTop = std::max(maxSingle, lSum + rSum + node->value);

	    res = std::max(res, maxTop);
	    return maxSingle;
    }
};





int main(void) {
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

	std::cout << "Max Path Sum: " << tree.FindMaxPathSum();
	return 0;
}