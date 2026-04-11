## Overview
Learn the fundamental operations of creating a linked list from scratch and traversing through its nodes. This lesson covers three essential operations that form the foundation of linked list manipulation.

## Topics Covered
1. **Create Linked List**: Build a linked list by inserting nodes
2. **Traverse & Print**: Visit each node and print its value
3. **Count Nodes**: Calculate the total number of nodes in the list

## Problem Statement
Implement a singly linked list with the following operations:
- Create a linked list from an array of values
- Traverse the list and print all elements
- Count the total number of nodes


---

## Constraints

- `0 ≤ n ≤ 10⁴ (number of nodes)`
- `-10⁵ ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Head is null
2. **Single node:** Next is null
3. **Traversal prints all values:** Iterate until null
4. **Circular list (if malformed):** Infinite loop without detection
5. **Large list:** Memory allocation for each node

<br>

## Approach

### 1. Create Linked List
- Define a Node class with data and next pointer
- Create nodes and link them together
- Maintain a head pointer to the first node

### 2. Traverse & Print
- Start from the head node
- Visit each node using the next pointer
- Print the data of each node
- Stop when next is null

### 3. Count Nodes
- Initialize counter to 0
- Traverse the list
- Increment counter for each node
- Return the final count

## Complexity Analysis

### Time Complexity
- **Create**: O(n) where n is the number of elements
- **Traverse**: O(n) to visit all nodes
- **Count**: O(n) to count all nodes

### Space Complexity
- O(1) auxiliary space for all operations

## Key Points
- Head pointer is crucial for accessing the list
- Traversal is the basis for most linked list operations
- Always check for null to avoid errors
- Creating a list requires linking nodes sequentially

## Code

```code```
