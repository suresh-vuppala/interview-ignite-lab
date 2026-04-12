import java.util.*;
class Solution {
    Map<Integer,Integer> map = new HashMap<>(); int preIdx = 0;
    public TreeNode buildTree(int[] pre, int[] in) {
        for (int i=0;i<in.length;i++) map.put(in[i],i);
        preIdx=0; return build(pre,0,in.length-1);
    }
    TreeNode build(int[] pre, int l, int r) {
        if (l>r) return null;
        TreeNode root = new TreeNode(pre[preIdx++]);
        int idx = map.get(root.val);
        root.left = build(pre, l, idx-1);
        root.right = build(pre, idx+1, r);
        return root;
    }
}