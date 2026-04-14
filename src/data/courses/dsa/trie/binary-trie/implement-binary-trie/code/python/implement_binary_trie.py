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
        self.children = [None, None]  # 0 and 1 for binary

class ImplementBinaryTrie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num: int) -> None:
        node = self.root
        for i in range(31, -1, -1):  # Process from MSB to LSB
            bit = (num >> i) & 1  # Extract bit at position i
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def getMaxXor(self, num: int) -> int:
        node = self.root
        max_xor = 0
        for i in range(31, -1, -1):
            bit = (num >> i) & 1  # Current bit
            opposite_bit = 1 - bit  # Opposite bit for max XOR
            
            if node.children[opposite_bit]:
                max_xor |= (1 << i)  # Set bit in result
                node = node.children[opposite_bit]
            else:
                node = node.children[bit]  # Take same bit
        
        return max_xor
