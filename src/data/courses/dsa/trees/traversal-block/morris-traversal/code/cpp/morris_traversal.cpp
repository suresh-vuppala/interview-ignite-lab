// ============================================================
// Morris Inorder Traversal — O(1) Space
// ============================================================
#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<int> morrisInorder(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                // No left child — process and go right
                result.push_back(current->val);
                current = current->right;
            } else {
                // Find inorder predecessor (rightmost in left subtree)
                TreeNode* pred = current->left;
                while (pred->right && pred->right != current)
                    pred = pred->right;

                if (!pred->right) {
                    // First visit — create thread and go left
                    pred->right = current;
                    current = current->left;
                } else {
                    // Second visit — remove thread, process, go right
                    pred->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};
