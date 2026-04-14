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
        self.children = {}

class CountDistinctSubstrings:
    def countDistinct(self, s: str) -> int:
        root = TrieNode()
        count = 0
        
        # Insert all substrings
        for i in range(len(s)):
            node = root
            for j in range(i, len(s)):
                c = s[j]
                if c not in node.children:
                    node.children[c] = TrieNode()
                    count += 1  # New unique substring
                node = node.children[c]
        
        return count + 1  # +1 for empty string
