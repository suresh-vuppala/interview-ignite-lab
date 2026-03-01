# Identical Binary Trees

## Overview
Check if two binary trees are identical (same structure and values).

## Problem Statement
Determine if tree1 and tree2 are identical.

## Approach
- Base cases: both null (true), one null (false)
- Check values match, then recursively check subtrees
- Simple and elegant

## Complexity Analysis
- **Time**: O(min(n1, n2))
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
    
    return (p->val == q->val) && 
           isSameTree(p->left, q->left) && 
           isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    cout << "Same tree: " << (isSameTree(p, q) ? "Yes" : "No") << endl;
    return 0;
}
