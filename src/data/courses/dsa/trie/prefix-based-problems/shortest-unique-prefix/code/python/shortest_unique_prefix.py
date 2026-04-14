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
        self.prefix_count = 0  # Count of words passing through

class ShortestUniquePrefix:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.prefix_count += 1  # Increment count
    
    def findPrefix(self, word: str) -> str:
        node = self.root
        prefix = []
        
        for c in word:
            prefix.append(c)
            node = node.children[c]
            
            if node.prefix_count == 1:
                return ''.join(prefix)  # Unique prefix found
        
        return word  # Entire word is the prefix
    
    def shortestUniquePrefixes(self, words: list[str]) -> list[str]:
        # Build trie with prefix counts
        for word in words:
            self.insert(word)
        
        # Find shortest unique prefix for each word
        result = []
        for word in words:
            result.append(self.findPrefix(word))
        return result
