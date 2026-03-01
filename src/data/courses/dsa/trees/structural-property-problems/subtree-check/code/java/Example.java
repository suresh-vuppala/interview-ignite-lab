public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    private boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        return (p.val == q.val) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) return false;
        
        if (isSameTree(root, subRoot)) return true;
        
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(4);
        root.right = new TreeNode(5);
        
        TreeNode subRoot = new TreeNode(4);
        subRoot.left = new TreeNode(1);
        subRoot.right = new TreeNode(2);
        
        Example sol = new Example();
        System.out.println("Is subtree: " + sol.isSubtree(root, subRoot));
    }
}
