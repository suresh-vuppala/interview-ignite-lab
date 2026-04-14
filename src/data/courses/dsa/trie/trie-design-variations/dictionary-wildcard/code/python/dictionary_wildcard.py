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
        self.is_end = False

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()
    
    def addWord(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True
    
    def search(self, word):
        return self._search_helper(word, 0, self.root)
    
    def _search_helper(self, word, index, node):
        if index == len(word):
            return node.is_end
        
        char = word[index]
        if char == '.':
            for child in node.children.values():
                if self._search_helper(word, index + 1, child):
                    return True
            return False
        else:
            if char not in node.children:
                return False
            return self._search_helper(word, index + 1, node.children[char])
