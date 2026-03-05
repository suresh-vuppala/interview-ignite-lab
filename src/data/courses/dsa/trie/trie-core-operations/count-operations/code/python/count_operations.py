class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary for child nodes
        self.word_count = 0  # Count of words ending here
        self.prefix_count = 0  # Count of words passing through

class CountOperations:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.prefix_count += 1  # Increment prefix count
        node.word_count += 1  # Increment word count at end
    
    def countWordsEqualTo(self, word: str) -> int:
        node = self.root
        for c in word:
            if c not in node.children:
                return 0  # Word doesn't exist
            node = node.children[c]
        return node.word_count  # Return count of this exact word
    
    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.root
        for c in prefix:
            if c not in node.children:
                return 0  # Prefix doesn't exist
            node = node.children[c]
        return node.prefix_count  # Return count of words with this prefix
