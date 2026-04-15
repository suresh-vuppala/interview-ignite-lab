struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: DFS with string building — O(N*H)
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, string path, vector<string>& res) {
        if(!n) return;
        path += to_string(n->val);
        if(!n->left&&!n->right) { res.push_back(path); return; }
        path += "->"; dfs(n->left,path,res); dfs(n->right,path,res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) { vector<string> res; dfs(root,"",res); return res; }
};

// ============================================================
// Solution 2: DFS with vector path — O(N*H)
// ============================================================
class Solution2 {
    void dfs(TreeNode* n, vector<int>& path, vector<string>& res) {
        if(!n) return; path.push_back(n->val);
        if(!n->left&&!n->right) { string s; for(int i=0;i<(int)path.size();i++){if(i)s+="->";s+=to_string(path[i]);}res.push_back(s); }
        dfs(n->left,path,res); dfs(n->right,path,res); path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) { vector<string> res;vector<int>p; dfs(root,p,res); return res; }
};
