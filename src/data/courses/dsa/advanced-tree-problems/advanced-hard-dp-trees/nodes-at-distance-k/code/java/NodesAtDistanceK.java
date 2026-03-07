// Time: O(N)
// Space: O(N)

import java.util.*;

public class NodesAtDistanceK {
    /**
     * Find all nodes at distance k from target
     */
    public static List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        buildParent(root, null, parent);
        
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        List<Integer> result = new ArrayList<>();
        
        queue.offer(target);
        visited.add(target);
        int dist = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            
            if (dist == k) {
                for (int i = 0; i < size; i++) {
                    result.add(queue.poll().val);
                }
                return result;
            }
            
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                
                if (node.left != null && !visited.contains(node.left)) {
                    visited.add(node.left);
                    queue.offer(node.left);
                }
                if (node.right != null && !visited.contains(node.right)) {
                    visited.add(node.right);
                    queue.offer(node.right);
                }
                if (parent.get(node) != null && !visited.contains(parent.get(node))) {
                    visited.add(parent.get(node));
                    queue.offer(parent.get(node));
                }
            }
            dist++;
        }
        
        return result;
    }
    
    private static void buildParent(TreeNode node, TreeNode par, Map<TreeNode, TreeNode> parent) {
        if (node == null) return;
        parent.put(node, par);
        buildParent(node.left, node, parent);
        buildParent(node.right, node, parent);
    }
    
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(5);
        root.right = new TreeNode(1);
        TreeNode target = root.left;
        int k = 2;
        
        List<Integer> result = distanceK(root, target, k);
        System.out.println("Nodes at distance " + k + ": " + result);
    }
}
