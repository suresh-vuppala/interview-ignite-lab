import java.util.*;
class Solution {
    public List<Integer> verticalSum(TreeNode root) {
        TreeMap<Integer,Integer> sums = new TreeMap<>();
        Queue<Object[]> q = new LinkedList<>(); if(root!=null)q.add(new Object[]{root,0});
        while(!q.isEmpty()){Object[]c=q.poll();TreeNode n=(TreeNode)c[0];int hd=(int)c[1];
            sums.merge(hd,n.val,Integer::sum);
            if(n.left!=null)q.add(new Object[]{n.left,hd-1});
            if(n.right!=null)q.add(new Object[]{n.right,hd+1});}
        return new ArrayList<>(sums.values());
    }
}