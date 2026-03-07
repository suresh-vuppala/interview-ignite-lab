from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# ==================== SOLUTION 1: DFS TWO PASS ====================
# Time: O(N) | Space: O(H)

def is_cousins_dfs_two_pass(root, x, y):
    """Find each node separately, then compare."""
    
    def find_node(node, target, parent, depth):
        if not node:
            return None
        if node.val == target:
            return (depth, parent)
        
        left = find_node(node.left, target, node, depth + 1)
        if left:
            return left
        return find_node(node.right, target, node, depth + 1)
    
    x_info = find_node(root, x, None, 0)
    y_info = find_node(root, y, None, 0)
    
    if not x_info or not y_info:
        return False
    
    x_depth, x_parent = x_info
    y_depth, y_parent = y_info
    
    return x_depth == y_depth and x_parent != y_parent


# ==================== SOLUTION 2: DFS SINGLE PASS ====================
# Time: O(N) | Space: O(H)

def is_cousins_dfs_single_pass(root, x, y):
    """Find both nodes in single DFS traversal."""
    x_info = [None, None]  # [depth, parent]
    y_info = [None, None]
    
    def dfs(node, parent, depth):
        if not node:
            return
        
        if node.val == x:
            x_info[0], x_info[1] = depth, parent
        if node.val == y:
            y_info[0], y_info[1] = depth, parent
        
        # Early termination if both found
        if x_info[0] is not None and y_info[0] is not None:
            return
        
        dfs(node.left, node, depth + 1)
        dfs(node.right, node, depth + 1)
    
    dfs(root, None, 0)
    
    if x_info[0] is None or y_info[0] is None:
        return False
    
    return x_info[0] == y_info[0] and x_info[1] != y_info[1]


# ==================== SOLUTION 3: BFS LEVEL ORDER ====================
# Time: O(N) | Space: O(W)

def is_cousins_bfs(root, x, y):
    """Process level by level, track parents."""
    if not root:
        return False
    
    queue = deque([(root, None)])
    
    while queue:
        level_size = len(queue)
        x_parent = None
        y_parent = None
        
        for _ in range(level_size):
            node, parent = queue.popleft()
            
            if node.val == x:
                x_parent = parent
            if node.val == y:
                y_parent = parent
            
            if node.left:
                queue.append((node.left, node))
            if node.right:
                queue.append((node.right, node))
        
        # Both found at same level
        if x_parent and y_parent:
            return x_parent != y_parent
        
        # Only one found at this level
        if x_parent or y_parent:
            return False
    
    return False


# ==================== SOLUTION 4: OPTIMIZED DFS ====================
# Time: O(N) | Space: O(H)

def is_cousins_optimized(root, x, y):
    """Single pass with early termination."""
    
    def dfs(node, parent, depth):
        if not node:
            return None
        
        # Check if children are x and y (siblings)
        if node.left and node.right:
            if (node.left.val == x and node.right.val == y) or \
               (node.left.val == y and node.right.val == x):
                return False  # Same parent, not cousins
        
        # Found target node
        if node.val == x or node.val == y:
            return (depth, parent)
        
        left = dfs(node.left, node, depth + 1)
        right = dfs(node.right, node, depth + 1)
        
        # Both found in subtrees
        if left and right:
            if isinstance(left, tuple) and isinstance(right, tuple):
                return left[0] == right[0]  # Same depth
        
        return left or right
    
    result = dfs(root, None, 0)
    return result if isinstance(result, bool) else False


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def isCousins(root, x, y):
    """
    Check if two nodes are cousins.
    
    Time: O(N) - BFS traversal
    Space: O(W) - queue width
    
    Example:
        >>> root = TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3))
        >>> isCousins(root, 4, 3)
        False
    """
    return is_cousins_bfs(root, x, y)
