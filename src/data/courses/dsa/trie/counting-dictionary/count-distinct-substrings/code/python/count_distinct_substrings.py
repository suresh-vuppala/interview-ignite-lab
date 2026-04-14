# ============================================================
# Solution 1: HashSet — O(N³) generate all substrings
# ============================================================
class Solution1:
    def countDistinct(self, s):
        substrings = set()
        n = len(s)
        for i in range(n):
            for j in range(i + 1, n + 1):
                substrings.add(s[i:j])  # O(N) per substring creation
        return len(substrings)

# ============================================================
# Solution 2: Suffix Trie — O(N²) insert suffixes, count nodes
# ============================================================
class Solution2:
    def countDistinct(self, s):
        root = {}
        count = 0
        for i in range(len(s)):
            node = root
            for j in range(i, len(s)):
                if s[j] not in node:
                    node[s[j]] = {}
                    count += 1  # New node = new distinct substring
                node = node[s[j]]
        return count
