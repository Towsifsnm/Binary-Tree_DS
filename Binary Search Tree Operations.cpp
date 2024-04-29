/*Write functions to insert a node, delete a node, and search for a node in a binary
search tree.*/


#include <iostream>

using namespace std;

// Definition of a binary search tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node into a binary search tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}

// Function to find the minimum node in a binary search tree
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from a binary search tree
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) return root;

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node found
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Function to search for a node in a binary search tree
bool searchNode(TreeNode* root, int val) {
    if (root == nullptr) return false;
    if (root->val == val) return true;
    if (val < root->val) return searchNode(root->left, val);
    else return searchNode(root->right, val);
}

int main() {
    TreeNode* root = nullptr;

    // Insert some nodes into the binary search tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search for a node
    int searchValue = 70;
    if (searchNode(root, searchValue)) {
        cout << searchValue << " is found in the binary search tree." << endl;
    } else {
        cout << searchValue << " is not found in the binary search tree." << endl;
    }

    // Delete a node
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "After deleting " << deleteValue << ": ";
    if (searchNode(root, deleteValue)) {
        cout << deleteValue << " is found in the binary search tree." << endl;
    } else {
        cout << deleteValue << " is not found in the binary search tree." << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

