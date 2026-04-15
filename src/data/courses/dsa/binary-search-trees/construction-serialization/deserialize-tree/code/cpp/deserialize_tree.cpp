struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <string>
#include <sstream>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Preorder recursive deserialization — O(N)
// ============================================================
class Solution1 {
    TreeNode* build(istringstream& ss) {
        string val; if(!getline(ss,val,',')) return nullptr;
        if(val=="#") return nullptr;
        TreeNode*node=new TreeNode(stoi(val));
        node->left=build(ss); node->right=build(ss);
        return node;
    }
public:
    TreeNode* deserialize(string data) { istringstream ss(data); return build(ss); }
};

// ============================================================
// Solution 2: BFS level-order deserialization — O(N)
// ============================================================
class Solution2 {
public:
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        istringstream ss(data); string val; getline(ss,val,',');
        TreeNode*root=new TreeNode(stoi(val));
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            auto n=q.front();q.pop();
            if(getline(ss,val,',')&&val!="#"){n->left=new TreeNode(stoi(val));q.push(n->left);}
            if(getline(ss,val,',')&&val!="#"){n->right=new TreeNode(stoi(val));q.push(n->right);}
        }
        return root;
    }
};
