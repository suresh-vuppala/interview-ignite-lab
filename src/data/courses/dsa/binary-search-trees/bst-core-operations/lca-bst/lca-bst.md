# LCA in BST

## Overview
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree using BST properties.

## Problem Statement
Given a BST and two node values, find their LCA.

## Approach
- **Using BST Property**: If both values < current, go left; if both > current, go right; otherwise found LCA
- **Time**: O(log n) average, O(n) worst case
- More efficient than general BT due to ordering property

## Complexity Analysis
- **Time**: O(log n) average, O(n) worst
- **Space**: O(1) iterative, O(h) recursive

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    
    // Both p and q are in left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    
    // Both p and q are in right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    
    // They are on different sides or one is the root
    return root;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA: " << lca->val << endl;
    return 0;
}
