def kruskal_mst(V, edges):
    parent = list(range(V))
    def find(x):
        while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
        return x
    def union(a, b):
        a, b = find(a), find(b)
        if a == b: return False
        parent[b] = a; return True
    
    edges.sort(key=lambda e: e[2])
    total, count = 0, 0
    for u, v, w in edges:
        if union(u, v): total += w; count += 1
        if count == V - 1: break
    return total