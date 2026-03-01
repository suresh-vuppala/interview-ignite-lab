#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    // Swap children
    swap(root->left, root->right);
    
    // Recursively invert subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    invertTree(root);
    cout << "Tree inverted. Root: " << root->val << endl;
    return 0;
}
