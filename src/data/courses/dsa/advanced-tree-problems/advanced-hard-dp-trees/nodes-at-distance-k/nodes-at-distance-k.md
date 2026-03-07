## Problem Statement

Given the root of a binary tree, a target node, and an integer `k`, return an array of the values of all nodes that have a distance `k` from the target node.

You can return the answer in any order.

## Examples

### Example 1
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: Nodes at distance 2 from target node 5 are: 7, 4, and 1
```

### Example 2
```
Input: root = [1], target = 1, k = 3
Output: []
Explanation: No nodes at distance 3
```

## Visual Walkthrough

### Example Tree
```
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

Target = 5, k = 2
```

**Distance from target node 5:**
- Distance 0: [5]
- Distance 1: [3, 6, 2]
- Distance 2: [1, 7, 4] ← Answer

### Approach Visualization

```
Step 1: Build parent pointers
        3 (parent: null)
       / \
      5   1
   parent: 3

Step 2: BFS from target with distance tracking
Level 0: [5]
Level 1: [3, 6, 2]
Level 2: [1, 7, 4] ← Collect these
```

## Algorithm

### Approach 1: Parent Pointers + BFS

**Steps:**
1. Build a parent map using DFS/BFS
2. Start BFS from target node
3. Track visited nodes to avoid cycles
4. When distance reaches k, collect all nodes

### Approach 2: DFS with Distance Tracking

**Steps:**
1. Find distance from target going down
2. Find distance from target going up through ancestors
3. Combine results from both directions

## Complexity Analysis

### Time Complexity: **O(N)**

**Why?**
- Building parent map: O(N)
- BFS traversal: O(N)
- Each node visited once
- Total: O(N)

### Space Complexity: **O(N)**

**Why?**
- Parent map: O(N)
- Queue for BFS: O(N) worst case
- Visited set: O(N)
- Total: O(N)

## Edge Cases

1. **Target is root**:
   ```
   root = [1,2,3], target = 1, k = 1
   Output: [2,3]
   ```

2. **k = 0**:
   ```
   Output: [target.val]
   ```

3. **k exceeds tree height**:
   ```
   Output: []
   ```

4. **Single node tree**:
   ```
   root = [1], target = 1, k = 0
   Output: [1]
   ```

## Common Mistakes

1. **Forgetting parent pointers**: Can't traverse upward without them
2. **Not tracking visited nodes**: Creates infinite loops
3. **Wrong distance calculation**: Off-by-one errors
4. **Not handling null nodes**: Causes null pointer exceptions

## Related Problems

- Binary Tree Level Order Traversal
- All Nodes Distance K in Binary Tree
- Amount of Time for Binary Tree to Be Infected

## Key Takeaways

- Parent pointers enable upward traversal in trees
- BFS naturally tracks distance levels
- Visited set prevents revisiting nodes
- Problem requires bidirectional tree traversal

```code```
