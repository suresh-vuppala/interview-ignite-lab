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
        self.word = None  # Store word at end

class BoggleBoard:
    def __init__(self):
        self.dirs = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]  # 8 directions
    
    def insert(self, root: TrieNode, word: str) -> None:
        node = root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.word = word  # Store complete word
    
    def dfs(self, board: list[list[str]], i: int, j: int, node: TrieNode, result: list[str]) -> None:
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return
        
        c = board[i][j]
        if c == '#' or c not in node.children:
            return  # Visited or no path
        
        node = node.children[c]
        if node.word:
            result.append(node.word)  # Found word
            node.word = None  # Avoid duplicates
        
        board[i][j] = '#'  # Mark visited
        for di, dj in self.dirs:  # Explore 8 directions
            self.dfs(board, i + di, j + dj, node, result)
        board[i][j] = c  # Backtrack
    
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        root = TrieNode()
        for word in words:
            self.insert(root, word)
        
        result = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, i, j, root, result)
        return result
