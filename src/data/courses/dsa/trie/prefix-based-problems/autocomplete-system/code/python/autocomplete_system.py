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
        self.sentences = {}  # sentence -> frequency

class AutocompleteSystem:
    def __init__(self, sentences: list[str], times: list[int]):
        self.root = TrieNode()
        self.current = self.root
        self.prefix = ""
        
        # Insert all sentences with frequencies
        for sentence, freq in zip(sentences, times):
            self.insert(sentence, freq)
    
    def insert(self, sentence: str, freq: int) -> None:
        node = self.root
        for c in sentence:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.sentences[sentence] = node.sentences.get(sentence, 0) + freq
    
    def getTop3(self, sentences: dict) -> list[str]:
        # Sort by frequency (desc), then lexicographically (asc)
        sorted_sentences = sorted(sentences.items(), 
                                 key=lambda x: (-x[1], x[0]))
        return [s[0] for s in sorted_sentences[:3]]
    
    def input(self, c: str) -> list[str]:
        if c == '#':
            # Save current sentence
            self.insert(self.prefix, 1)
            self.prefix = ""
            self.current = self.root
            return []
        
        self.prefix += c
        if c not in self.current.children:
            self.current.children[c] = TrieNode()
        self.current = self.current.children[c]
        
        # Get top 3 sentences
        return self.getTop3(self.current.sentences)
