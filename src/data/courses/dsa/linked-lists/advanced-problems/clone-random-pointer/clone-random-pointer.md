# Clone Linked List with Random Pointer

## Overview
Create a deep copy of a linked list where each node has a next and random pointer.

## Topics Covered
1. **Interweaving Technique**: Insert copies between original nodes
2. **Copy Random Pointers**: Use interweaved structure to set random
3. **Separate Lists**: Extract the copied list
4. **HashMap Alternative**: Map original to copy nodes

## Problem Statement
Given a linked list where each node has:
- `next`: Points to next node
- `random`: Points to any node or null

Create a deep copy of the list.

## Approach

### Method 1: Interweaving (O(1) space)
1. Insert copy nodes: A->A'->B->B'->C->C'
2. Set random pointers: A'.random = A.random.next
3. Separate lists: Extract A'->B'->C'
- Time: O(n), Space: O(1)

### Method 2: HashMap (O(n) space)
1. First pass: Create all nodes, map original to copy
2. Second pass: Set next and random using map
- Time: O(n), Space: O(n)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1) interweaving, O(n) hashmap

## Code

```code```