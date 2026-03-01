# LCA in Binary Tree

## Overview
Find Lowest Common Ancestor in a general binary tree (not necessarily BST).

## Problem Statement
Given binary tree and two nodes, find their LCA.

## Approach
- Post-order DFS
- If both found in left/right, recurse
- If found in current, return current
- Handle edge cases

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

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
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA: " << lca->val << endl;
    return 0;
}
