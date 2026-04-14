# ============================================================
# Solution 1: DFS per word — O(W*M*N*4^L) — search each separately
# ============================================================
class Solution1:
    def findWords(self, board, words):
        m, n = len(board), len(board[0])
        def dfs(word, i, r, c):
            if i == len(word): return True
            if r<0 or r>=m or c<0 or c>=n or board[r][c] != word[i]: return False
            tmp, board[r][c] = board[r][c], '#'
            found = dfs(word,i+1,r+1,c) or dfs(word,i+1,r-1,c) or dfs(word,i+1,r,c+1) or dfs(word,i+1,r,c-1)
            board[r][c] = tmp
            return found
        result = []
        for w in words:
            for r in range(m):
                for c in range(n):
                    if dfs(w, 0, r, c): result.append(w); break
                else: continue
                break
        return result

# ============================================================
# Solution 2: Trie + single DFS — O(M*N*4^L) — search all at once
# ============================================================
class TrieNode:
    def __init__(self): self.children, self.word = {}, None

class Solution2:
    def findWords(self, board, words):
        root = TrieNode()
        for w in words:
            node = root
            for c in w:
                if c not in node.children: node.children[c] = TrieNode()
                node = node.children[c]
            node.word = w
        m, n, result = len(board), len(board[0]), []
        def dfs(r, c, node):
            if r<0 or r>=m or c<0 or c>=n or board[r][c] == '#': return
            ch = board[r][c]
            nxt = node.children.get(ch)
            if not nxt: return
            if nxt.word: result.append(nxt.word); nxt.word = None
            board[r][c] = '#'
            dfs(r+1,c,nxt); dfs(r-1,c,nxt); dfs(r,c+1,nxt); dfs(r,c-1,nxt)
            board[r][c] = ch
        for r in range(m):
            for c in range(n):
                dfs(r, c, root)
        return result
