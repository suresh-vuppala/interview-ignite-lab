// ============================================================
// Maximum Width of Binary Tree
// ============================================================
import java.util.*;
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int max = 0;
        Queue<long[]> q = new LinkedList<>(); // [node_id, pos]
        q.add(new long[]{0, 0}); // Using array for simplicity
        // Actually need node reference — use parallel queue
        Queue<TreeNode> nq = new LinkedList<>();
        nq.add(root);
        Queue<Long> pq = new LinkedList<>();
        pq.add(0L);
        while (!nq.isEmpty()) {
            int size = nq.size();
            long minPos = pq.peek(), first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = nq.poll();
                long pos = pq.poll() - minPos;
                if (i == 0) first = pos;
                if (i == size-1) last = pos;
                if (node.left != null) { nq.add(node.left); pq.add(2*pos); }
                if (node.right != null) { nq.add(node.right); pq.add(2*pos+1); }
            }
            max = Math.max(max, (int)(last - first + 1));
        }
        return max;
    }
}
