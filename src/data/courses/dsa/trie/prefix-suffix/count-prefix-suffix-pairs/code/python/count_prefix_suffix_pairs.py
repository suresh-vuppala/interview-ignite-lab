# ============================================================
# Solution 1: Brute Force - Check All Pairs
# Time: O(N² × L) | Space: O(1)
# ============================================================
class Solution1:
    def countPrefixSuffixPairs(self, words):
        count = 0
        n = len(words)
        
        # Check every pair (i, j) where i < j
        for i in range(n):
            for j in range(i + 1, n):
                # Skip if words[i] is longer than words[j]
                if len(words[i]) > len(words[j]):
                    continue
                
                # Check if words[i] is both prefix and suffix of words[j]
                if self.is_prefix_and_suffix(words[i], words[j]):
                    count += 1
        
        return count
    
    def is_prefix_and_suffix(self, str1, str2):
        # Check if str1 is both prefix and suffix of str2
        return str2.startswith(str1) and str2.endswith(str1)


# ============================================================
# Solution 2: Double Trie (Prefix Trie + Suffix Trie)
# Time: O(N × L²) | Space: O(N × L)
# ============================================================
class TrieNode:
    def __init__(self):
        self.children = {}
        self.word_indices = []

class Solution2:
    def countPrefixSuffixPairs(self, words):
        n = len(words)
        prefix_root = TrieNode()
        suffix_root = TrieNode()
        
        # Build prefix trie and suffix trie
        for i in range(n):
            self.insert_prefix(prefix_root, words[i], i)
            self.insert_suffix(suffix_root, words[i], i)
        
        count = 0
        # For each word, find matches
        for j in range(n):
            prefix_matches = self.search_prefix(prefix_root, words[j])
            suffix_matches = self.search_suffix(suffix_root, words[j])
            
            # Find intersection (words that are both prefix and suffix)
            suffix_set = set(suffix_matches)
            for i in prefix_matches:
                if i < j and i in suffix_set:
                    count += 1
        
        return count
    
    def insert_prefix(self, root, word, index):
        node = root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.word_indices.append(index)
    
    def insert_suffix(self, root, word, index):
        node = root
        # Insert reversed word
        for c in reversed(word):
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.word_indices.append(index)
    
    def search_prefix(self, root, word):
        result = []
        node = root
        
        for c in word:
            if c not in node.children:
                break
            node = node.children[c]
            result.extend(node.word_indices)
        
        return result
    
    def search_suffix(self, root, word):
        result = []
        node = root
        
        # Search with reversed word
        for c in reversed(word):
            if c not in node.children:
                break
            node = node.children[c]
            result.extend(node.word_indices)
        
        return result


# ============================================================
# Solution 3: Combined Trie (Optimal)
# Time: O(N × L²) | Space: O(N × L)
# ============================================================
class PairTrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0

class Solution:
    def countPrefixSuffixPairs(self, words):
        root = PairTrieNode()
        total_count = 0
        
        for word in words:
            # Search first: count how many existing words are prefix-suffix of current word
            total_count += self.search(root, word)
            
            # Then insert current word
            self.insert(root, word)
        
        return total_count
    
    def insert(self, root, word):
        node = root
        length = len(word)
        
        # Traverse from both ends simultaneously
        for i in range(length):
            key = (ord(word[i]) << 8) | ord(word[length - 1 - i])
            
            if key not in node.children:
                node.children[key] = PairTrieNode()
            node = node.children[key]
        
        node.count += 1
    
    def search(self, root, word):
        node = root
        length = len(word)
        count = 0
        
        # Traverse from both ends simultaneously
        for i in range(length):
            key = (ord(word[i]) << 8) | ord(word[length - 1 - i])
            
            if key not in node.children:
                break
            node = node.children[key]
            count += node.count
        
        return count
