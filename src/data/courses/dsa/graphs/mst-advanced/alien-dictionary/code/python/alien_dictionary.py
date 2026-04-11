class Solution:
    def alienOrder(self, words: List[str]) -> str:
        from collections import defaultdict, deque
        adj = defaultdict(set); indeg = {c:0 for w in words for c in w}
        for i in range(len(words)-1):
            w1, w2 = words[i], words[i+1]
            if len(w1)>len(w2) and w1[:len(w2)]==w2: return ""
            for a,b in zip(w1,w2):
                if a!=b:
                    if b not in adj[a]: adj[a].add(b); indeg[b]+=1
                    break
        q = deque(c for c in indeg if indeg[c]==0); result = []
        while q:
            c = q.popleft(); result.append(c)
            for nb in adj[c]:
                indeg[nb]-=1
                if indeg[nb]==0: q.append(nb)
        return ''.join(result) if len(result)==len(indeg) else '' 