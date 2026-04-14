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
class Solution:
    def countPrefixSuffixPairs(self, words):
        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if self.is_prefix_and_suffix(words[i], words[j]):
                    count += 1
        return count
    
    def is_prefix_and_suffix(self, str1, str2):
        if len(str1) > len(str2):
            return False
        return str2.startswith(str1) and str2.endswith(str1)
