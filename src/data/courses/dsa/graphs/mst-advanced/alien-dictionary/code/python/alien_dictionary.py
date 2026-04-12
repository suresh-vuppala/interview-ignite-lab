# ============================================================
# Alien Dictionary
# ============================================================
from collections import defaultdict, deque
class Solution:
    def alienOrder(self, words):
        adj = defaultdict(set)
        in_deg = {c: 0 for w in words for c in w}
        # Compare adjacent words
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i+1]
            if len(w1) > len(w2) and w1[:len(w2)] == w2: return ""
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    if c2 not in adj[c1]:
                        adj[c1].add(c2); in_deg[c2] += 1
                    break
        # Kahn's
        queue = deque(c for c in in_deg if in_deg[c] == 0)
        result = []
        while queue:
            c = queue.popleft(); result.append(c)
            for nb in adj[c]:
                in_deg[nb] -= 1
                if in_deg[nb] == 0: queue.append(nb)
        return ''.join(result) if len(result) == len(in_deg) else ''
