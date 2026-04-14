# ============================================================
# Solution 1: Brute Force — Hash Set / Direct comparison
# Time: O(N*L) or O(N²*L) | Space: O(N*L)
# ============================================================
class Solution1:
    def __init__(self): self.words = set()
    def insert(self, word): self.words.add(word)
    def hasPrefix(self, prefix):
        return any(w.startswith(prefix) for w in self.words)

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
        self.is_end = False

class sumprefixscores:
    def __init__(self):
        self.root = TrieNode()
    # Minimal implementation
