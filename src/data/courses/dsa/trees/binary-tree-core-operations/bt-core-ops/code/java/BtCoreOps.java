// ============================================================
// Binary Tree Core Operations (BST)
// ============================================================

class TreeNode {
    int val; TreeNode left, right;
    TreeNode(int v) { val = v; }
}

class BSTOperations {
    public TreeNode insert(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insert(root.left, val);
        else if (val > root.val) root.right = insert(root.right, val);
        return root;
    }

    public boolean search(TreeNode root, int val) {
        if (root == null) return false;
        if (val == root.val) return true;
        return val < root.val ? search(root.left, val) : search(root.right, val);
    }

    public TreeNode deleteNode(TreeNode root, int val) {
        if (root == null) return null;
        if (val < root.val) root.left = deleteNode(root.left, val);
        else if (val > root.val) root.right = deleteNode(root.right, val);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            TreeNode succ = root.right;
            while (succ.left != null) succ = succ.left;
            root.val = succ.val;
            root.right = deleteNode(root.right, succ.val);
        }
        return root;
    }
}
