// Time: O(N)
// Space: O(N)

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NodesAtDistanceK {
public:
    /**
     * Find all nodes at distance k from target
     */
    static vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, nullptr, parent);
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        vector<int> result;
        
        q.push(target);
        visited.insert(target);
        int dist = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            if (dist == k) {
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }
        
        return result;
    }
    
private:
    static void buildParent(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        parent[node] = par;
        buildParent(node->left, node, parent);
        buildParent(node->right, node, parent);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    TreeNode* target = root->left;
    int k = 2;
    
    vector<int> result = NodesAtDistanceK::distanceK(root, target, k);
    cout << "Nodes at distance " << k << ": ";
    for (int val : result) cout << val << " ";
    cout << endl;
    
    return 0;
}
