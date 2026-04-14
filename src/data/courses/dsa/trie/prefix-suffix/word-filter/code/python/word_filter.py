# ============================================================
# Solution 1: Brute Force — Linear scan all words O(N*L)
# ============================================================
class Solution1:
    def __init__(self): self.words = []
    def addWord(self, word): self.words.append(word)
    def search(self, query):
        result = []
        for w in self.words:
            if len(w) != len(query): continue
            if all(q == '.' or q == c for q, c in zip(query, w)):
                result.append(w)
        return result

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
        self.weight = -1

class WordFilter:
    def __init__(self, words):
        self.root = TrieNode()
        for weight, word in enumerate(words):
            for i in range(len(word) + 1):
                suffix = word[i:]
                key = suffix + '#' + word
                self._insert(key, weight)
    
    def _insert(self, word, weight):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.weight = weight
    
    def f(self, prefix, suffix):
        node = self.root
        search_key = suffix + '#' + prefix
        for char in search_key:
            if char not in node.children:
                return -1
            node = node.children[char]
        return node.weight
