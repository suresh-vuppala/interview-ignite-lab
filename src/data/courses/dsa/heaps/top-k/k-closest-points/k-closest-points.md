## Problem Statement

Given an array of points where `points[i] = [xi, yi]` represents a point on the X-Y plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the Euclidean distance: `√(x² + y²)`.

### Example

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation: Distance from origin: (1,3) = √10, (-2,2) = √8

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
```

## Approach

### Max Heap Approach
- Use a max heap of size k
- For each point, calculate distance and add to heap
- If heap size > k, remove the farthest point
- Time: O(n log k), Space: O(k)

### Quick Select Approach
- Partition array based on distance
- Find kth smallest distance
- Time: O(n) average, Space: O(1)

## Complexity Analysis

### Time Complexity: O(n log k)
- Process n points: O(n)
- Each heap operation: O(log k)
- Overall: O(n log k)

### Space Complexity: O(k)
- Max heap stores k points

## Key Insights

- Use max heap to maintain k closest points
- No need to calculate actual square root (compare squared distances)
- Heap automatically maintains k smallest elements

## Code

```code```