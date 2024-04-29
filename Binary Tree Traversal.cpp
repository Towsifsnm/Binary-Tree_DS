
 /*Implement the pre-order, in-order, and post-order traversal algorithms for a binary
tree.*/



 #include <iostream>

using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " "; //   current node
    preOrder(root->left);     //  left subtree
    preOrder(root->right);    //   right subtree
}

// Function to perform in-order traversal
void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);      //  left subtree
    cout << root->val << " "; //  current node
    inOrder(root->right);     //  right subtree
}

// Function to perform post-order traversal
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);    //   left subtree
    postOrder(root->right);   //   right subtree
    cout << root->val << " "; //  current node
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
