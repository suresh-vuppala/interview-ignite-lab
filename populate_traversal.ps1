$basePath = "d:\interview-ignite-lab\src\data\courses\dsa"

# Traversal Block Lessons
$traversalLessons = @{
    "trees\traversal-block\inorder" = @{
        markdown = @"
# Inorder Traversal

## Overview
Inorder traversal visits nodes in Left-Root-Right order. For BSTs, this produces sorted output.

## Problem Statement
Implement inorder traversal (recursive and iterative) for a binary tree.

## Approach
**Recursive**: Visit left subtree, process root, visit right subtree
**Iterative**: Use stack to simulate recursion

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h) for recursion, O(h) for iterative

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderRecursive(root->left, result);
    result.push_back(root->val);
    inorderRecursive(root->right, result);
}

vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<int> res;
    inorderRecursive(root, res);
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
"@;
        java = @"
import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static List<Integer> inorder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        inorderHelper(root, result);
        return result;
    }
    
    static void inorderHelper(TreeNode root, List<Integer> result) {
        if (root == null) return;
        inorderHelper(root.left, result);
        result.add(root.val);
        inorderHelper(root.right, result);
    }
    
    static List<Integer> inorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root;
        
        while (curr != null || !st.isEmpty()) {
            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }
            curr = st.pop();
            result.add(curr.val);
            curr = curr.right;
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(inorder(root));
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def inorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    inorder_recursive(root.left, result)
    result.append(root.val)
    inorder_recursive(root.right, result)
    return result

def inorder_iterative(root):
    result = []
    stack = []
    curr = root
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        result.append(curr.val)
        curr = curr.right
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(inorder_recursive(root))
"@;
    };

    "trees\traversal-block\preorder" = @{
        markdown = @"
# Preorder Traversal

## Overview
Preorder traversal visits nodes in Root-Left-Right order. Useful for copying trees and prefix expressions.

## Problem Statement
Implement preorder traversal (recursive and iterative).

## Approach
**Recursive**: Process root, visit left subtree, visit right subtree
**Iterative**: Use single stack

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderRecursive(root->left, result);
    preorderRecursive(root->right, result);
}

vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        result.push_back(curr->val);
        
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<int> res;
    preorderRecursive(root, res);
    for (int v : res) cout << v << " ";
    return 0;
}
"@;
        java = @"
import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static List<Integer> preorder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        preorderHelper(root, result);
        return result;
    }
    
    static void preorderHelper(TreeNode root, List<Integer> result) {
        if (root == null) return;
        result.add(root.val);
        preorderHelper(root.left, result);
        preorderHelper(root.right, result);
    }
    
    static List<Integer> preorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        
        while (!st.isEmpty()) {
            TreeNode curr = st.pop();
            result.add(curr.val);
            if (curr.right != null) st.push(curr.right);
            if (curr.left != null) st.push(curr.left);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(preorder(root));
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def preorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    result.append(root.val)
    preorder_recursive(root.left, result)
    preorder_recursive(root.right, result)
    return result

def preorder_iterative(root):
    if not root:
        return []
    result = []
    stack = [root]
    
    while stack:
        curr = stack.pop()
        result.append(curr.val)
        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(preorder_recursive(root))
"@;
    };

    "trees\traversal-block\postorder" = @{
        markdown = @"
# Postorder Traversal

## Overview
Postorder traversal visits nodes in Left-Right-Root order. Used for deletion and solving subproblem-based problems.

## Problem Statement
Implement postorder traversal (recursive and iterative).

## Approach
**Recursive**: Visit left, visit right, process root
**Iterative**: Use two stacks or one stack with tracking

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

```code
```
"@;
        cpp = @"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorderRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderRecursive(root->left, result);
    postorderRecursive(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* top = st.top();
        if (top->right && top->right != lastVisited) {
            curr = top->right;
        } else {
            result.push_back(top->val);
            lastVisited = st.top();
            st.pop();
        }
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<int> res;
    postorderRecursive(root, res);
    for (int v : res) cout << v << " ";
    return 0;
}
"@;
        java = @"
import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static List<Integer> postorder(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        postorderHelper(root, result);
        return result;
    }
    
    static void postorderHelper(TreeNode root, List<Integer> result) {
        if (root == null) return;
        postorderHelper(root.left, result);
        postorderHelper(root.right, result);
        result.add(root.val);
    }
    
    static List<Integer> postorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root, lastVisited = null;
        
        while (curr != null || !st.isEmpty()) {
            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }
            TreeNode top = st.peek();
            if (top.right != null && top.right != lastVisited) {
                curr = top.right;
            } else {
                result.add(top.val);
                lastVisited = st.pop();
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(postorder(root));
    }
}
"@;
        python = @"
class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def postorder_recursive(root, result=None):
    if result is None:
        result = []
    if not root:
        return result
    postorder_recursive(root.left, result)
    postorder_recursive(root.right, result)
    result.append(root.val)
    return result

def postorder_iterative(root):
    if not root:
        return []
    result = []
    stack = []
    curr = root
    last_visited = None
    
    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left
        top = stack[-1]
        if top.right and top.right != last_visited:
            curr = top.right
        else:
            result.append(top.val)
            last_visited = stack.pop()
    
    return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print(postorder_recursive(root))
"@;
    };
}

# Write files
foreach ($lessonPath in $traversalLessons.Keys) {
    $content = $traversalLessons[$lessonPath]
    $slug = $lessonPath.Split('\')[-1]
    
    $mdPath = "$basePath\$lessonPath\$slug.md"
    $content.markdown | Out-File -FilePath $mdPath -Encoding UTF8 -Force
    
    $cppPath = "$basePath\$lessonPath\code\cpp\Example.cpp"
    $content.cpp | Out-File -FilePath $cppPath -Encoding UTF8 -Force
    
    $javaPath = "$basePath\$lessonPath\code\java\Example.java"
    $content.java | Out-File -FilePath $javaPath -Encoding UTF8 -Force
    
    $pyPath = "$basePath\$lessonPath\code\python\example.py"
    $content.python | Out-File -FilePath $pyPath -Encoding UTF8 -Force
}

Write-Host "Populated Traversal Block lessons (3: Inorder, Preorder, Postorder)"
