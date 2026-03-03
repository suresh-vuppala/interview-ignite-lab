from collections import deque

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def levelOrder(root):
    if not root:
        return []
    
    result = []
    q = deque([root])
    
    while q:
        size = len(q)
        level = []
        
        for _ in range(size):
            node = q.popleft()
            level.append(node.val)
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        
        result.append(level)
    return result

if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    
    result = levelOrder(root)
    print("Level order traversal completed")
