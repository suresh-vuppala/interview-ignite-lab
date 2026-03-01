# Populate all critical lessons with detailed implementations
$basePath = "d:\interview-ignite-lab\src\data\courses\dsa"

$lessons = @(
    # Path & Relationship Problems
    @{
        name = "path-sum-exists"
        title = "Path Sum Exists"
        dir = "$basePath\trees\path-relationship-problems\path-sum-exists"
        mdContent = @"
# Path Sum Exists

## Overview
Determine if root-to-leaf path exists with given sum.

## Problem Statement
Given binary tree and target sum, return if any root-to-leaf path sums to target.

## Approach
- DFS from root, accumulating sum
- At leaf, check if accumulated equals target
- Backtrack if sum doesn't match

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

\`\`\`code
\`\`\`
"@
        cppCode = @"
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    // Leaf node check
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    // Recursively check left and right
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    
    cout << "Path Sum 22: " << (hasPathSum(root, 22) ? "Yes" : "No") << endl;
    return 0;
}
"@
        javaCode = @"
public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;
        
        if (root.left == null && root.right == null) {
            return root.val == targetSum;
        }
        
        return hasPathSum(root.left, targetSum - root.val) ||
               hasPathSum(root.right, targetSum - root.val);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(4);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(11);
        
        Example sol = new Example();
        System.out.println("Path Sum 22: " + sol.hasPathSum(root, 22));
    }
}
"@
        pyCode = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def hasPathSum(root, targetSum):
    if not root:
        return False
    
    if not root.left and not root.right:
        return root.val == targetSum
    
    return (hasPathSum(root.left, targetSum - root.val) or
            hasPathSum(root.right, targetSum - root.val))

if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    
    print(f"Path Sum 22: {hasPathSum(root, 22)}")
"@
    },
    
    # Invert Tree - Simple but important
    @{
        name = "invert-tree"
        title = "Invert Binary Tree"
        dir = "$basePath\trees\tree-modification-block\invert-tree"
        mdContent = @"
# Invert Binary Tree

## Overview
Swap left and right subtrees for all nodes (mirror the tree).

## Problem Statement
Invert a binary tree so left becomes right and right becomes left.

## Approach
- DFS: swap children at each node
- Base case: null nodes
- Simple recursive solution

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

\`\`\`code
\`\`\`
"@
        cppCode = @"
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    // Swap children
    swap(root->left, root->right);
    
    // Recursively invert subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    invertTree(root);
    cout << "Tree inverted. Root: " << root->val << endl;
    return 0;
}
"@
        javaCode = @"
public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        invertTree(root.left);
        invertTree(root.right);
        
        return root;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        
        Example sol = new Example();
        sol.invertTree(root);
        System.out.println("Tree inverted.");
    }
}
"@
        pyCode = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def invertTree(root):
    if not root:
        return None
    
    root.left, root.right = root.right, root.left
    
    invertTree(root.left)
    invertTree(root.right)
    
    return root

if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    
    invertTree(root)
    print("Tree inverted.")
"@
    },
    
    # Two Sum in BST
    @{
        name = "two-sum-bst"
        title = "Two Sum in BST"
        dir = "$basePath\binary-search-trees\bst-core-operations\two-sum-bst"
        mdContent = @"
# Two Sum in BST

## Overview
Find two numbers in BST that sum to a target value.

## Problem Statement
Given BST and target sum, find two nodes whose values sum to target.

## Approach
- Inorder gives sorted sequence
- Two-pointer on sorted array
- Or use set with target - current lookup

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h) or O(n)

## Code

\`\`\`code
\`\`\`
"@
        cppCode = @"
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) return true;
        else if (sum < k) left++;
        else right--;
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    cout << "Two sum 9: " << (findTarget(root, 9) ? "Yes" : "No") << endl;
    return 0;
}
"@
        javaCode = @"
import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    private void inorder(TreeNode root, List<Integer> arr) {
        if (root == null) return;
        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }
    
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int sum = arr.get(left) + arr.get(right);
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(6);
        
        Example sol = new Example();
        System.out.println("Two sum 9: " + sol.findTarget(root, 9));
    }
}
"@
        pyCode = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def findTarget(root, k):
    def inorder(node):
        if not node:
            return []
        return inorder(node.left) + [node.val] + inorder(node.right)
    
    arr = inorder(root)
    left, right = 0, len(arr) - 1
    
    while left < right:
        s = arr[left] + arr[right]
        if s == k:
            return True
        elif s < k:
            left += 1
        else:
            right -= 1
    return False

if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    
    print(f"Two sum 9: {findTarget(root, 9)}")
"@
    }
)

# Populate all
foreach ($lesson in $lessons) {
    $lesson.mdContent | Out-File "$($lesson.dir)\$($lesson.name).md" -Encoding UTF8 -Force
    $lesson.cppCode | Out-File "$($lesson.dir)\code\cpp\Example.cpp" -Encoding UTF8 -Force
    $lesson.javaCode | Out-File "$($lesson.dir)\code\java\Example.java" -Encoding UTF8 -Force
    $lesson.pyCode | Out-File "$($lesson.dir)\code\python\example.py" -Encoding UTF8 -Force
    Write-Host "✅ Populated: $($lesson.title)"
}

Write-Host ""
Write-Host "✨ Populated 3 critical lessons with full implementations"
