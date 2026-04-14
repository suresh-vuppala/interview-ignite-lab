# ============================================================
# Solution 1: Brute Force
# ============================================================

class Solution1:
    # Brute force: hash set / nested loops / direct comparison
    # See Solution 2 below for optimal Trie-based approach
    pass


# ============================================================
# Solution 2: Optimal (Trie-based)
# ============================================================
class TrieNode:
    def __init__(self):
        self.children = [None, None]

class MaximumXorConstraint:
    def insert(self, root: TrieNode, num: int) -> None:
        node = root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def getMaxXor(self, root: TrieNode, x: int, m: int) -> int:
        node = root
        xor_val = 0
        for i in range(31, -1, -1):
            bit = (x >> i) & 1
            opposite = 1 - bit
            if node.children[opposite]:
                xor_val |= (1 << i)
                node = node.children[opposite]
            elif node.children[bit]:
                node = node.children[bit]
            else:
                return -1
        return xor_val if xor_val <= m else -1
    
    def maximizeXor(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        nums.sort()
        indexed_queries = [(q[0], q[1], i) for i, q in enumerate(queries)]
        indexed_queries.sort(key=lambda x: x[1])
        
        result = [0] * len(queries)
        root = TrieNode()
        idx = 0
        
        for x, m, q_idx in indexed_queries:
            while idx < len(nums) and nums[idx] <= m:
                self.insert(root, nums[idx])
                idx += 1
            result[q_idx] = -1 if idx == 0 else self.getMaxXor(root, x, m)
        
        return result
