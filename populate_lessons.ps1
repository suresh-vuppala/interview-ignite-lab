$Error.Clear()
$basePath = "d:\interview-ignite-lab\src\data\courses\dsa"

# Define all lessons with their content
$lessons = @{
    # TREES MODULE
    "trees\binary-tree-core-operations\count-leaf-internal-nodes" = @{
        markdown = @"
# Count Leaf and Internal Nodes

## Overview
Leaf nodes have no children. Internal nodes have at least one child. This is a fundamental tree property counting problem.

## Problem Statement
Given a binary tree, count the number of leaf nodes and internal nodes.

## Approach
- **Leaf Node**: Node with no left and right children
- **Internal Node**: Node with at least one child
- Use DFS/recursion to traverse and count

## Complexity Analysis
- **Time**: O(n) - visit each node once
- **Space**: O(h) - recursion stack

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countLeafNodes(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    cout << "Leaf nodes: " << countLeafNodes(root) << endl;
    cout << "Internal nodes: " << countInternalNodes(root) << endl;
    return 0;
}
"@;
        java = @"
public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static int countLeafNodes(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        return countLeafNodes(root.left) + countLeafNodes(root.right);
    }
    
    static int countInternalNodes(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return 0;
        return 1 + countInternalNodes(root.left) + countInternalNodes(root.right);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("Leaf: " + countLeafNodes(root));
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def count_leaf_nodes(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    return count_leaf_nodes(root.left) + count_leaf_nodes(root.right)

def count_internal_nodes(root):
    if not root or (not root.left and not root.right):
        return 0
    return 1 + count_internal_nodes(root.left) + count_internal_nodes(root.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(f"Leaf nodes: {count_leaf_nodes(root)}")
"@;
    };

    "trees\binary-tree-core-operations\height-of-tree" = @{
        markdown = @"
# Height of Tree

## Overview
The height of a tree is the longest path from root to any leaf node. Also called depth in some contexts.

## Problem Statement
Find the height of a binary tree.

## Approach
- **Base Case**: Empty tree has height -1 (or 0 depending on convention)
- **Recursive Case**: Height = 1 + max(height of left subtree, height of right subtree)
- Can use DFS with recursion

## Complexity Analysis
- **Time**: O(n) - visit each node
- **Space**: O(h) - recursion stack

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    cout << "Height: " << getHeight(root) << endl;
    return 0;
}
"@;
        java = @"
public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static int getHeight(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("Height: " + getHeight(root));
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def get_height(root):
    if not root:
        return 0
    return 1 + max(get_height(root.left), get_height(root.right))

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(f"Height: {get_height(root)}")
"@;
    };

    "trees\binary-tree-core-operations\max-min-value" = @{
        markdown = @"
# Max and Min Values

## Overview
Find the maximum and minimum values in a binary tree by traversing all nodes.

## Problem Statement
Given a binary tree, find both the maximum and minimum node values.

## Approach
- Traverse all nodes (preorder, inorder, or postorder)
- Track min and max during traversal
- Can use recursion or iteration with queue/stack

## Complexity Analysis
- **Time**: O(n) - visit every node
- **Space**: O(h) - recursion or queue space

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> findMinMax(TreeNode* root) {
    if (!root) return {INT_MAX, INT_MIN};
    
    auto [leftMin, leftMax] = findMinMax(root->left);
    auto [rightMin, rightMax] = findMinMax(root->right);
    
    int minVal = min({root->val, leftMin, rightMin});
    int maxVal = max({root->val, leftMax, rightMax});
    
    return {minVal, maxVal};
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    auto [minVal, maxVal] = findMinMax(root);
    cout << "Min: " << minVal << ", Max: " << maxVal << endl;
    return 0;
}
"@;
        java = @"
public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static class MinMax {
        int min, max;
        MinMax(int mn, int mx) { min = mn; max = mx; }
    }
    
    static MinMax findMinMax(TreeNode root) {
        if (root == null) 
            return new MinMax(Integer.MAX_VALUE, Integer.MIN_VALUE);
        
        MinMax left = findMinMax(root.left);
        MinMax right = findMinMax(root.right);
        
        int min = Math.min(root.val, Math.min(left.min, right.min));
        int max = Math.max(root.val, Math.max(left.max, right.max));
        
        return new MinMax(min, max);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(15);
        MinMax result = findMinMax(root);
        System.out.println("Min: " + result.min + ", Max: " + result.max);
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def find_min_max(root):
    if not root:
        return (float('inf'), float('-inf'))
    
    left_min, left_max = find_min_max(root.left)
    right_min, right_max = find_min_max(root.right)
    
    min_val = min(root.val, left_min, right_min)
    max_val = max(root.val, left_max, right_max)
    
    return (min_val, max_val)

if __name__ == "__main__":
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    min_val, max_val = find_min_max(root)
    print(f"Min: {min_val}, Max: {max_val}")
"@;
    };
}

# Write files
foreach ($lessonPath in $lessons.Keys) {
    $content = $lessons[$lessonPath]
    
    # Write markdown
    $mdPath = "$basePath\$lessonPath\$($lessonPath.Split('\')[-1]).md"
    $content.markdown | Out-File -FilePath $mdPath -Encoding UTF8 -Force
    
    # Write code files
    $cppPath = "$basePath\$lessonPath\code\cpp\Example.cpp"
    $content.cpp | Out-File -FilePath $cppPath -Encoding UTF8 -Force
    
    $javaPath = "$basePath\$lessonPath\code\java\Example.java"
    $content.java | Out-File -FilePath $javaPath -Encoding UTF8 -Force
    
    $pyPath = "$basePath\$lessonPath\code\python\example.py"
    $content.python | Out-File -FilePath $pyPath -Encoding UTF8 -Force
}

Write-Host "Populated remaining Binary Tree Core Operations lessons (3 lessons)"
