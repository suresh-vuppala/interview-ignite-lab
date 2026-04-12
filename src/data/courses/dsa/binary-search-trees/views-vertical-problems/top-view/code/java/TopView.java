import java.util.*;
class Solution {
    public List<Integer> topView(TreeNode root) {
        if (root==null) return new ArrayList<>();
        TreeMap<Integer,Integer> map = new TreeMap<>();
        Queue<Object[]> q = new LinkedList<>(); q.add(new Object[]{root,0});
        while (!q.isEmpty()) { Object[] c = q.poll(); TreeNode n=(TreeNode)c[0]; int hd=(int)c[1];
            map.putIfAbsent(hd, n.val);
            if(n.left!=null) q.add(new Object[]{n.left,hd-1});
            if(n.right!=null) q.add(new Object[]{n.right,hd+1}); }
        return new ArrayList<>(map.values());
    }
}