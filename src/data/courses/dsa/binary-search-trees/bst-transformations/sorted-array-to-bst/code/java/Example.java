import java.util.*;

public class Example {
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) { val = x; }
    }
    
    private TreeNode sortedArrayToBST(int[] nums, int left, int right) {
        if (left > right) return null;
        
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        
        root.left = sortedArrayToBST(nums, left, mid - 1);
        root.right = sortedArrayToBST(nums, mid + 1, right);
        
        return root;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length - 1);
    }
    
    public static void main(String[] args) {
        int[] nums = {-10, -3, 0, 5, 9};
        Example sol = new Example();
        TreeNode root = sol.sortedArrayToBST(nums);
        System.out.println("BST created with root: " + root.val);
    }
}
