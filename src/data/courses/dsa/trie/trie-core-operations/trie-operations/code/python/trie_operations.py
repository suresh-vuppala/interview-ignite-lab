class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary for child nodes
        self.is_end = False  # Marks end of word

class TrieOperations:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()  # Create new node
            node = node.children[c]  # Move to child
        node.is_end = True  # Mark end of word
    
    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            if c not in node.children:
                return False  # Path doesn't exist
            node = node.children[c]
        return node.is_end  # Check if it's a complete word
    
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if c not in node.children:
                return False  # Path doesn't exist
            node = node.children[c]
        return True  # Prefix exists (don't check is_end)
