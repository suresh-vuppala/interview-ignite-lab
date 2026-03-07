// Time: O(N) | Space: O(H)

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private int maxSum = 0;
    
    class Result {
        boolean isBst;
        int sum, min, max;
        Result(boolean b, int s, int mn, int mx) {
            isBst = b; sum = s; min = mn; max = mx;
        }
    }
    
    public int maxSumBST(TreeNode root) {
        dfs(root);
        return maxSum;
    }
    
    private Result dfs(TreeNode node) {
        if (node == null) {
            return new Result(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }
        
        Result left = dfs(node.left);
        Result right = dfs(node.right);
        
        if (left.isBst && right.isBst && left.max < node.val && node.val < right.min) {
            int currSum = left.sum + right.sum + node.val;
            maxSum = Math.max(maxSum, currSum);
            return new Result(true, currSum, Math.min(left.min, node.val), Math.max(right.max, node.val));
        }
        
        return new Result(false, 0, 0, 0);
    }
}
