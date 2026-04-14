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

class ReplaceWords:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True  # Mark root word end
    
    def getRoot(self, word: str) -> str:
        node = self.root
        prefix = ""
        for c in word:
            if c not in node.children:
                break  # No root found
            prefix += c
            node = node.children[c]
            if node.is_end:
                return prefix  # Found shortest root
        return word  # No root found, return original
    
    def replaceWords(self, dictionary: list[str], sentence: str) -> str:
        # Insert all roots into trie
        for word in dictionary:
            self.insert(word)
        
        # Process sentence
        words = sentence.split()
        result = []
        for word in words:
            result.append(self.getRoot(word))  # Replace with root if exists
        return ' '.join(result)
