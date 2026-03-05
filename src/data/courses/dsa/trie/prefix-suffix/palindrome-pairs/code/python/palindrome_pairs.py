class TrieNode:
    def __init__(self):
        self.children = {}
        self.index = -1
        self.palindrome_suffixes = []

class Solution:
    def palindromePairs(self, words):
        root = TrieNode()
        
        # Build trie with reversed words
        for i, word in enumerate(words):
            node = root
            for j in range(len(word) - 1, -1, -1):
                if self.is_palindrome(word, 0, j):
                    node.palindrome_suffixes.append(i)
                char = word[j]
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.index = i
            node.palindrome_suffixes.append(i)
        
        result = []
        for i, word in enumerate(words):
            node = root
            for j, char in enumerate(word):
                if node.index >= 0 and node.index != i and self.is_palindrome(word, j, len(word) - 1):
                    result.append([i, node.index])
                if char not in node.children:
                    break
                node = node.children[char]
            else:
                for idx in node.palindrome_suffixes:
                    if idx != i:
                        result.append([i, idx])
        return result
    
    def is_palindrome(self, word, left, right):
        while left < right:
            if word[left] != word[right]:
                return False
            left += 1
            right -= 1
        return True
