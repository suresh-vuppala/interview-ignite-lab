class Solution:
    def rob(self,root)->int:
        def dfs(node):
            if not node:return(0,0)
            ls,lt=dfs(node.left);rs,rt=dfs(node.right)
            skip=max(ls,lt)+max(rs,rt);take=node.val+ls+rs
            return(skip,take)
        return max(dfs(root))