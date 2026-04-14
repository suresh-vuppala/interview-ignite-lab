# ============================================================
# Solution 1: Vertical Scanning — O(N*L) time, O(1) space
# ============================================================
class Solution1:
    def longestCommonPrefix(self, strs):
        if not strs: return ""
        for i in range(len(strs[0])):
            c = strs[0][i]
            for s in strs[1:]:
                if i >= len(s) or s[i] != c:
                    return strs[0][:i]
        return strs[0]

# ============================================================
# Solution 2: Trie — Insert all, walk single-child path
# ============================================================
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Solution2:
    def longestCommonPrefix(self, strs):
        if not strs: return ""
        root = TrieNode()
        for s in strs:
            node = root
            for c in s:
                if c not in node.children: node.children[c] = TrieNode()
                node = node.children[c]
            node.is_end = True
        prefix, node = "", root
        while len(node.children) == 1 and not node.is_end:
            c = next(iter(node.children))
            prefix += c; node = node.children[c]
        return prefix
