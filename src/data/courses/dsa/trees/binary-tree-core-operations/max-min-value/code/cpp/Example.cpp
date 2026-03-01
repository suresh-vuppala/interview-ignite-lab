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
