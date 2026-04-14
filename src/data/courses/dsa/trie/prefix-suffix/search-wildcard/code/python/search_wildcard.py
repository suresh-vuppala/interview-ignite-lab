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
        self.word = None

class Solution:
    def __init__(self):
        self.root = TrieNode()
    
    def addWord(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True
        node.word = word
    
    def search(self, pattern):
        result = []
        self._dfs(self.root, pattern, 0, result)
        return result
    
    def _dfs(self, node, pattern, index, result):
        if index == len(pattern):
            if node.is_end:
                result.append(node.word)
            return
        
        char = pattern[index]
        if char == '.':
            for child in node.children.values():
                self._dfs(child, pattern, index + 1, result)
        elif char == '*':
            # Match zero or more characters
            self._dfs(node, pattern, index + 1, result)  # Match zero
            for child in node.children.values():
                self._dfs(child, pattern, index, result)  # Match one or more
        else:
            if char in node.children:
                self._dfs(node.children[char], pattern, index + 1, result)
