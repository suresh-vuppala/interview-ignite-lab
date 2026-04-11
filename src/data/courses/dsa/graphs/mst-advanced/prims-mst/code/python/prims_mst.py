import heapq
def prim_mst(V, adj):
    in_mst = [False] * V
    heap = [(0, 0)]  # (weight, vertex)
    total = 0
    while heap:
        w, u = heapq.heappop(heap)
        if in_mst[u]: continue
        in_mst[u] = True; total += w
        for v, wt in adj[u]:
            if not in_mst[v]: heapq.heappush(heap, (wt, v))
    return total