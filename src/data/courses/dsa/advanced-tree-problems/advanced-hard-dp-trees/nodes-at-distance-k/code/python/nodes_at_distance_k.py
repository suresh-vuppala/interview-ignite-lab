def distance_k(root, target, k):
    """
    Find all nodes at distance k from target
    Time: O(N), Space: O(N)
    """
    parent = {}
    
    def build_parent(node, par=None):
        if not node:
            return
        parent[node] = par
        build_parent(node.left, node)
        build_parent(node.right, node)
    
    build_parent(root)
    
    queue = [(target, 0)]
    visited = {target}
    result = []
    
    while queue:
        node, dist = queue.pop(0)
        
        if dist == k:
            result.append(node.val)
            continue
        
        for neighbor in [node.left, node.right, parent[node]]:
            if neighbor and neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, dist + 1))
    
    return result

if __name__ == "__main__":
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right
    
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    target = root.left
    k = 2
    
    result = distance_k(root, target, k)
    print(f"Nodes at distance {k}: {result}")
