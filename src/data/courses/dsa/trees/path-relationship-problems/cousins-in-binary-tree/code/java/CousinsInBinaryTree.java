import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

public class CousinsInBinaryTree {
    
    // ==================== SOLUTION 1: DFS TWO PASS ====================
    // Time: O(N) | Space: O(H)
    
    public static boolean isCousinsDFSTwoPass(TreeNode root, int x, int y) {
        int[] xInfo = findNode(root, x, null, 0);
        int[] yInfo = findNode(root, y, null, 0);
        
        if (xInfo == null || yInfo == null) return false;
        
        return xInfo[0] == yInfo[0] && xInfo[1] != yInfo[1];
    }
    
    private static int[] findNode(TreeNode node, int target, TreeNode parent, int depth) {
        if (node == null) return null;
        if (node.val == target) {
            return new int[]{depth, parent == null ? -1 : parent.val};
        }
        
        int[] left = findNode(node.left, target, node, depth + 1);
        if (left != null) return left;
        return findNode(node.right, target, node, depth + 1);
    }
    
    
    // ==================== SOLUTION 2: DFS SINGLE PASS ====================
    // Time: O(N) | Space: O(H)
    
    static int xDepth, yDepth;
    static TreeNode xParent, yParent;
    
    public static boolean isCousinsDFSSinglePass(TreeNode root, int x, int y) {
        xDepth = yDepth = -1;
        xParent = yParent = null;
        
        dfs(root, null, 0, x, y);
        
        return xDepth == yDepth && xParent != yParent;
    }
    
    private static void dfs(TreeNode node, TreeNode parent, int depth, int x, int y) {
        if (node == null) return;
        
        if (node.val == x) {
            xDepth = depth;
            xParent = parent;
        }
        if (node.val == y) {
            yDepth = depth;
            yParent = parent;
        }
        
        if (xDepth != -1 && yDepth != -1) return;
        
        dfs(node.left, node, depth + 1, x, y);
        dfs(node.right, node, depth + 1, x, y);
    }
    
    
    // ==================== SOLUTION 3: BFS LEVEL ORDER ====================
    // Time: O(N) | Space: O(W)
    
    public static boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) return false;
        
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, null));
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            TreeNode xParent = null, yParent = null;
            
            for (int i = 0; i < size; i++) {
                Pair curr = queue.poll();
                TreeNode node = curr.node;
                TreeNode parent = curr.parent;
                
                if (node.val == x) xParent = parent;
                if (node.val == y) yParent = parent;
                
                if (node.left != null) queue.offer(new Pair(node.left, node));
                if (node.right != null) queue.offer(new Pair(node.right, node));
            }
            
            if (xParent != null && yParent != null) {
                return xParent != yParent;
            }
            if (xParent != null || yParent != null) {
                return false;
            }
        }
        
        return false;
    }
    
    static class Pair {
        TreeNode node;
        TreeNode parent;
        Pair(TreeNode node, TreeNode parent) {
            this.node = node;
            this.parent = parent;
        }
    }
}
