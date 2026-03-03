public class ValidateBST {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    private boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;
        
        if (root.val <= minVal || root.val >= maxVal) return false;
        
        return isValidBST(root.left, minVal, root.val) &&
               isValidBST(root.right, root.val, maxVal);
    }
    
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        
        Example sol = new Example();
        System.out.println("Is Valid BST: " + sol.isValidBST(root));
    }
}
