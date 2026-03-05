class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class LongestCommonPrefix:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True  # Mark end of word
    
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        
        # Insert all words into trie
        for word in strs:
            self.insert(word)
        
        # Traverse trie to find common prefix
        prefix = []
        node = self.root
        
        while True:
            # Count children
            children_list = list(node.children.keys())
            
            # Stop if branching or end of word
            if len(children_list) != 1 or node.is_end:
                break
            
            char = children_list[0]
            prefix.append(char)  # Add character to prefix
            node = node.children[char]  # Move to child
        
        return ''.join(prefix)
