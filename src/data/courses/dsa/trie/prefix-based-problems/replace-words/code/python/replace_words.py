# ============================================================
# Solution 1: HashSet — Check all prefixes O(W*L²)
# ============================================================
class Solution1:
    def replaceWords(self, dictionary, sentence):
        roots = set(dictionary)
        result = []
        for word in sentence.split():
            rep = word
            for i in range(1, len(word)+1):
                if word[:i] in roots: rep = word[:i]; break
            result.append(rep)
        return ' '.join(result)

# ============================================================
# Solution 2: Trie — O(L) prefix match per word
# ============================================================
class TrieNode:
    def __init__(self): self.children, self.is_end = {}, False

class Solution2:
    def replaceWords(self, dictionary, sentence):
        root = TrieNode()
        for word in dictionary:
            node = root
            for c in word:
                if c not in node.children: node.children[c] = TrieNode()
                node = node.children[c]
            node.is_end = True
        result = []
        for word in sentence.split():
            node, rep = root, word
            for i, c in enumerate(word):
                if c not in node.children: break
                node = node.children[c]
                if node.is_end: rep = word[:i+1]; break
            result.append(rep)
        return ' '.join(result)
