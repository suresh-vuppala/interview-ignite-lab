# Subtree of Another Tree

## Overview
Check if one tree is a subtree of another (exact match at some node).

## Problem Statement
Check if tree s is a subtree of tree t (starting at some node in t).

## Approach
- For each node in t, check if it matches s
- Use isSameTree helper
- DFS on t to find potential roots

## Complexity Analysis
- **Time**: O(n*m) where n=t.size, m=s.size
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    
    if (isSameTree(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    
    cout << "Is subtree: " << (isSubtree(root, subRoot) ? "Yes" : "No") << endl;
    return 0;
}
