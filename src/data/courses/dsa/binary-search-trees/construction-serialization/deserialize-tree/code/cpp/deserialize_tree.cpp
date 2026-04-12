// ============================================================
// Deserialize Binary Tree
// ============================================================
#include <string>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* parent = q.front(); q.pop();
            if (getline(ss, token, ',') && token != "null") {
                parent->left = new TreeNode(stoi(token));
                q.push(parent->left);
            }
            if (getline(ss, token, ',') && token != "null") {
                parent->right = new TreeNode(stoi(token));
                q.push(parent->right);
            }
        }
        return root;
    }
};
