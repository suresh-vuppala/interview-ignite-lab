# Validate BST

## Overview
Determine if a binary tree is a valid Binary Search Tree (BST). A valid BST must satisfy: left subtree values < node < right subtree values.

## Problem Statement
Given a binary tree, validate whether it is a Binary Search Tree (BST).

## Approach
1. **Min-Max Approach**: Track valid min/max bounds for each subtree
2. **Inorder Traversal**: Valid BST produces sorted inorder sequence
3. **Recursive**: For each node, ensure all left descendants < node < all right descendants

## Complexity Analysis
- **Time**: O(n) - visit each node once
- **Space**: O(h) - recursion depth

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Validate with min-max bounds
bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    
    // Current value must be within bounds
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    // Left subtree: all values must be < root->val
    // Right subtree: all values must be > root->val
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << "Is Valid BST: " << (isValidBST(root) ? "Yes" : "No") << endl;
    return 0;
}
