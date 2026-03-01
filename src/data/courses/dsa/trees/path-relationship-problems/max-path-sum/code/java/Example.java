public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    static int maxSum;
    
    private int maxPathSumHelper(TreeNode root) {
        if (root == null) return 0;
        
        int leftSum = Math.max(0, maxPathSumHelper(root.left));
        int rightSum = Math.max(0, maxPathSumHelper(root.right));
        
        int pathSum = root.val + leftSum + rightSum;
        maxSum = Math.max(maxSum, pathSum);
        
        return root.val + Math.max(leftSum, rightSum);
    }
    
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        maxPathSumHelper(root);
        return maxSum;
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        
        Example sol = new Example();
        System.out.println("Max Path Sum: " + sol.maxPathSum(root));
    }
}
