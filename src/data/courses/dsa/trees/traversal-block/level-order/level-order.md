# Level Order Traversal

## Overview
BFS traversal visiting nodes level-by-level (breadth-first).

## Problem Statement
Perform level order traversal returning list of lists (each inner list is one level).

## Approach
- Use queue: enqueue root, process level by level
- For each level, process all current nodes
- Add their children to queue

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(w) where w = max width

## Code

\\\code
\\\
"@

 = @"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    auto result = levelOrder(root);
    cout << "Level order traversal completed" << endl;
    return 0;
}
