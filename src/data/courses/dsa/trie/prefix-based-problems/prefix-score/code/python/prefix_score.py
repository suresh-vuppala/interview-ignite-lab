class TrieNode:
    def __init__(self):
        self.children = {}
        self.prefix_count = 0  # Count of words passing through

class PrefixScore:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.prefix_count += 1  # Increment count
    
    def getScore(self, word: str) -> int:
        node = self.root
        score = 0
        
        for c in word:
            node = node.children[c]
            score += node.prefix_count  # Add prefix count
        
        return score
    
    def sumPrefixScores(self, words: list[str]) -> int:
        # Build trie with prefix counts
        for word in words:
            self.insert(word)
        
        # Calculate sum of scores
        total_score = 0
        for word in words:
            total_score += self.getScore(word)
        return total_score
