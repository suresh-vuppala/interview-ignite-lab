## Queues — First In, First Out (FIFO)

A queue processes elements in the order they arrive — like a line at a store. The key variants are **circular queues** (efficient array-based) and **deques** (double-ended, used in sliding window problems).

<br>

## Why Queues Matter

- **BFS foundation** — Every BFS traversal uses a queue (graphs, trees, grids)
- **Sliding window maximum/minimum** — Monotonic deque gives O(n) solution
- **Design problems** — Circular queue, implement queue using stacks

<br>

## Queue Variants

| Variant | Operations | Use Case |
|---------|-----------|----------|
| Simple Queue | enqueue, dequeue | BFS, level-order traversal |
| Circular Queue | Fixed-size, wraps around | Buffer management, OS scheduling |
| Deque | push/pop from both ends | Sliding window max/min |
| Priority Queue | min/max extraction | Dijkstra, K-way merge (see Heaps) |

<br>
