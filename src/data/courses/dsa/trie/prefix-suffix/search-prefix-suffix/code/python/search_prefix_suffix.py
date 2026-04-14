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
        self.indices = []

class Solution:
    def __init__(self):
        self.forward_trie = TrieNode()
        self.reverse_trie = TrieNode()
    
    def build(self, words):
        for i, word in enumerate(words):
            # Insert into forward trie
            node = self.forward_trie
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.indices.append(i)
            
            # Insert into reverse trie
            node = self.reverse_trie
            for char in reversed(word):
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.indices.append(i)
    
    def search(self, prefix, suffix):
        # Find prefix matches
        node = self.forward_trie
        for char in prefix:
            if char not in node.children:
                return []
            node = node.children[char]
        prefix_indices = self._collect_all(node)
        
        # Find suffix matches
        node = self.reverse_trie
        for char in reversed(suffix):
            if char not in node.children:
                return []
            node = node.children[char]
        suffix_indices = self._collect_all(node)
        
        # Return intersection
        return list(set(prefix_indices) & set(suffix_indices))
    
    def _collect_all(self, node):
        result = node.indices[:]
        for child in node.children.values():
            result.extend(self._collect_all(child))
        return result
