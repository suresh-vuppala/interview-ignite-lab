# Max Path Sum

## Overview
Find the maximum path sum in a binary tree. Path can start/end at any node (not necessarily root to leaf).

## Problem Statement
Return the maximum path sum where path can include any nodes.

## Approach
- DFS postorder: calculate max path through each node
- At each node, decide: continue path or start new
- Track global max during traversal
- Handle negative values: can ignore subtrees

## Complexity Analysis
- **Time**: O(n) - visit each node
- **Space**: O(h) - recursion stack

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxSum = INT_MIN;

int maxPathSumHelper(TreeNode* root) {
    if (!root) return 0;
    
    int leftSum = max(0, maxPathSumHelper(root->left));
    int rightSum = max(0, maxPathSumHelper(root->right));
    
    // Current path sum through this node
    int pathSum = root->val + leftSum + rightSum;
    maxSum = max(maxSum, pathSum);
    
    // Return max path ending at this node
    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    maxPathSumHelper(root);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << "Max Path Sum: " << maxPathSum(root) << endl;
    return 0;
}
