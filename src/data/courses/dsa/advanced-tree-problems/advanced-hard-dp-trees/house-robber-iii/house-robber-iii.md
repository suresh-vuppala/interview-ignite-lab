# House Robber III

## Overview
Tree DP problem: rob houses on tree without robbing adjacent nodes.

## Problem Statement
Each node is a house with money. Rob houses without robbing parent-child neighbors.

## Approach
- DP on tree: state = (rob current, skip current)
- For each node: max = rob + skip(children) OR skip + rob(children)
- DFS return [robbed, skipped]

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto [leftRob, leftSkip] = dfs(root->left);
    auto [rightRob, rightSkip] = dfs(root->right);
    
    // Rob current: skip children
    int rob = root->val + leftSkip + rightSkip;
    
    // Skip current: children can be robbed or skipped
    int skip = max(leftRob, leftSkip) + max(rightRob, rightSkip);
    
    return {rob, skip};
}

int rob(TreeNode* root) {
    auto [robbed, skipped] = dfs(root);
    return max(robbed, skipped);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    
    cout << "Max money: " << rob(root) << endl;
    return 0;
}
