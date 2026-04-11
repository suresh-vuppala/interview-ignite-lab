def floyd_warshall(V, edges):
    INF = float('inf')
    dist = [[INF]*V for _ in range(V)]
    for i in range(V): dist[i][i] = 0
    for u, v, w in edges: dist[u][v] = w
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist