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
        self.word = None

class FindWordsGrid:
    def insert(self, root: TrieNode, word: str) -> None:
        node = root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.word = word
    
    def dfs(self, board: list[list[str]], i: int, j: int, node: TrieNode, result: list[str]) -> None:
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return
        c = board[i][j]
        if c == '#' or c not in node.children:
            return
        
        node = node.children[c]
        if node.word:
            result.append(node.word)
            node.word = None
        
        board[i][j] = '#'
        self.dfs(board, i + 1, j, node, result)
        self.dfs(board, i - 1, j, node, result)
        self.dfs(board, i, j + 1, node, result)
        self.dfs(board, i, j - 1, node, result)
        board[i][j] = c
    
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        root = TrieNode()
        for word in words:
            self.insert(root, word)
        
        result = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, i, j, root, result)
        return result
