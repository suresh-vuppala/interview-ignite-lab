# ============================================================
# Solution 1: Brute Force Recursion — O(2^N)
# ============================================================
class Solution1:
    def wordBreak(self, s, wordDict):
        words = set(wordDict)
        def canBreak(start):
            if start == len(s): return True
            for end in range(start+1, len(s)+1):
                if s[start:end] in words and canBreak(end): return True
            return False
        return canBreak(0)

# ============================================================
# Solution 2: Trie + DP — O(N*L)
# ============================================================
class TrieNode:
    def __init__(self): self.children, self.is_end = {}, False

class Solution2:
    def wordBreak(self, s, wordDict):
        root = TrieNode()
        for word in wordDict:
            node = root
            for c in word:
                if c not in node.children: node.children[c] = TrieNode()
                node = node.children[c]
            node.is_end = True
        n = len(s)
        dp = [False] * (n + 1); dp[0] = True
        for i in range(n):
            if not dp[i]: continue
            node = root
            for j in range(i, n):
                if s[j] not in node.children: break
                node = node.children[s[j]]
                if node.is_end: dp[j+1] = True
        return dp[n]
