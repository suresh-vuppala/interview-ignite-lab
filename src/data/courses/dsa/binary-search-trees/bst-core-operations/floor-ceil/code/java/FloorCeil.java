// ============================================================
// Floor and Ceil in BST
// ============================================================
class Solution {
    public int floor(TreeNode root, int key) {
        int res = -1;
        while (root != null) {
            if (root.val == key) return key;
            if (root.val < key) { res = root.val; root = root.right; }
            else root = root.left;
        }
        return res;
    }
    public int ceil(TreeNode root, int key) {
        int res = -1;
        while (root != null) {
            if (root.val == key) return key;
            if (root.val > key) { res = root.val; root = root.left; }
            else root = root.right;
        }
        return res;
    }
}
