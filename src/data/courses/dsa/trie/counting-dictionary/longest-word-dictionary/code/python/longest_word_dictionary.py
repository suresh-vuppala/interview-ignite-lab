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
