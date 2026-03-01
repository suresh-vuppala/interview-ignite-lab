# Check if Balanced Tree

## Overview
Determine if binary tree is height-balanced (height difference  1 for all subtrees).

## Problem Statement
A balanced tree has left/right height difference  1 at each node.

## Approach
- Recursive: get height, check balance at each level
- Return -1 if unbalanced (pruning)
- Time: O(n) due to early termination

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root) {
    if (!root) return 0;
    
    int left = getHeight(root->left);
    if (left == -1) return -1;
    
    int right = getHeight(root->right);
    if (right == -1) return -1;
    
    if (abs(left - right) > 1) return -1;
    
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return getHeight(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    return 0;
}
