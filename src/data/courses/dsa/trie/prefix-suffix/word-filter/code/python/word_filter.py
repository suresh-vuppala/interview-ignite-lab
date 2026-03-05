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
