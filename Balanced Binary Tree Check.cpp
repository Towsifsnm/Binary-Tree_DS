/*Given a binary tree, determine if it is height-balanced (i.e., the height
difference between the left and right subtrees of any node is not greater
than 1).*/


#include <iostream>
#include <algorithm>

using namespace std;

// binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of a binary tree
int height(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

//  check  a binary tree is height-balanced
bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check   the height difference of the left and right subtrees is not greater than 1
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (isBalanced(root))
        cout << "The binary tree is height-balanced." << endl;
    else
        cout << "The binary tree is not height-balanced." << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

