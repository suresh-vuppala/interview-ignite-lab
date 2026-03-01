# Sorted Array to BST

## Overview
Convert sorted array to height-balanced BST using divide-and-conquer.

## Problem Statement
Build height-balanced BST from sorted array (O(n) time).

## Approach
- Pick middle element as root (ensures balance)
- Recursively build left from left half
- Recursively build right from right half

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(log n)

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

TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    cout << "BST created with root: " << root->val << endl;
    return 0;
}
