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

class LongestWordDictionary:
    def insert(self, root: TrieNode, word: str) -> None:
        node = root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True
    
    def canBuild(self, root: TrieNode, word: str) -> bool:
        node = root
        for c in word:
            node = node.children[c]
            if not node.is_end:
                return False  # Each prefix must be a word
        return True
    
    def longestWord(self, words: list[str]) -> str:
        root = TrieNode()
        for word in words:
            self.insert(root, word)
        
        longest = ""
        for word in words:
            if self.canBuild(root, word):
                if len(word) > len(longest) or (len(word) == len(longest) and word < longest):
                    longest = word
        return longest
