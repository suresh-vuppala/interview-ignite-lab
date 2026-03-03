#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    TreeNode* root;
public:
    void insert(int val) {
        if (!root) { root = new TreeNode(val); return; }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr->left) { curr->left = new TreeNode(val); return; }
            if (!curr->right) { curr->right = new TreeNode(val); return; }
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    
    TreeNode* search(int val) {
        return searchHelper(root, val);
    }
    
private:
    TreeNode* searchHelper(TreeNode* node, int val) {
        if (!node) return nullptr;
        if (node->val == val) return node;
        TreeNode* left = searchHelper(node->left, val);
        return left ? left : searchHelper(node->right, val);
    }
};

int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    cout << (bt.search(5) ? "Found" : "Not found") << endl;
    return 0;
}
