Move N disks from source rod to destination rod following specific rules.

<br>

> Input:
> N = 3 disks

> Output:
> Move disk 1 from A to C
> Move disk 2 from A to B
> Move disk 1 from C to B
> Move disk 3 from A to C
> Move disk 1 from B to A
> Move disk 2 from B to C
> Move disk 1 from A to C

> Explanation:
> 7 moves needed to transfer 3 disks from rod A to rod C
> 
> **Key insight:** Recursive solution - move N-1 disks to auxiliary, move largest, move N-1 to destination.

<br>

---

## Problem: Tower of Hanoi

**Rules:**
1. Only one disk can be moved at a time
2. Only the top disk from any rod can be moved
3. A larger disk cannot be placed on a smaller disk

**Goal:** Move all N disks from source rod to destination rod.

**Example:**
```
Initial (N=3):
Rod A: [3, 2, 1]  (3 is largest, 1 is smallest)
Rod B: []
Rod C: []

Final:
Rod A: []
Rod B: []
Rod C: [3, 2, 1]
```

<br>


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

## Solution: Recursive Divide & Conquer

**Intuition:**
To move N disks from A to C:
1. Move top N-1 disks from A to B (using C as auxiliary)
2. Move largest disk from A to C
3. Move N-1 disks from B to C (using A as auxiliary)

**Key Insight:** Solving for N disks uses solution for N-1 disks twice!

**Algorithm:**
```cpp
towerOfHanoi(n, source, destination, auxiliary):
    if n == 1:
        print "Move disk 1 from", source, "to", destination
        return
    
    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n-1, source, auxiliary, destination)
    
    // Step 2: Move largest disk from source to destination
    print "Move disk", n, "from", source, "to", destination
    
    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n-1, auxiliary, destination, source)
```

**Detailed Example for N=3:**
```
Initial: A=[3,2,1], B=[], C=[]

Call: hanoi(3, A, C, B)
  Call: hanoi(2, A, B, C)
    Call: hanoi(1, A, C, B)
      Move disk 1: A to C
      A=[3,2], B=[], C=[1]
    Move disk 2: A to B
    A=[3], B=[2], C=[1]
    Call: hanoi(1, C, B, A)
      Move disk 1: C to B
      A=[3], B=[2,1], C=[]
  
  Move disk 3: A to C
  A=[], B=[2,1], C=[3]
  
  Call: hanoi(2, B, C, A)
    Call: hanoi(1, B, A, C)
      Move disk 1: B to A
      A=[1], B=[2], C=[3]
    Move disk 2: B to C
    A=[1], B=[], C=[3,2]
    Call: hanoi(1, A, C, B)
      Move disk 1: A to C
      A=[], B=[], C=[3,2,1]

Final: A=[], B=[], C=[3,2,1] ✓
```

<br>

---

## Recursion Tree

**For N=3:**
```
                    hanoi(3, A, C, B)
                   /       |        \
          hanoi(2,A,B,C)  Move 3  hanoi(2,B,C,A)
         /      |      \           /      |      \
    h(1,A,C,B) M2 h(1,C,B,A)  h(1,B,A,C) M2 h(1,A,C,B)
       |              |           |              |
      M1             M1          M1             M1
```

**Tree Properties:**
- Height: N (recursion depth)
- Nodes: 2^N - 1 (total moves)
- Each level doubles the number of calls

<br>

---

## Recurrence Relation

**Moves Required:**
```
T(n) = 2T(n-1) + 1

Where:
- T(n-1): Move n-1 disks to auxiliary
- 1: Move largest disk
- T(n-1): Move n-1 disks to destination

Base case: T(1) = 1
```

**Solving:**
```
T(n) = 2T(n-1) + 1
     = 2(2T(n-2) + 1) + 1
     = 4T(n-2) + 2 + 1
     = 4(2T(n-3) + 1) + 2 + 1
     = 8T(n-3) + 4 + 2 + 1
     = ...
     = 2^(n-1) × T(1) + (2^(n-1) - 1)
     = 2^(n-1) + 2^(n-1) - 1
     = 2^n - 1
```

**Result:** Exactly 2^N - 1 moves needed.

<br>

---

## Complexity Analysis

### Time Complexity: O(2^N)
**Why?**
- Recurrence: T(n) = 2T(n-1) + O(1)
- Solution: T(n) = 2^n - 1
- Each disk doubles the number of moves

**Detailed breakdown:**
- N=1: 1 move
- N=2: 3 moves
- N=3: 7 moves
- N=4: 15 moves
- N=10: 1,023 moves
- N=64: 18,446,744,073,709,551,615 moves (legend says world ends!)

### Space Complexity: O(N)
**Why?**
- Maximum recursion depth: N
- Each call uses O(1) space
- Call stack: O(N)

**Detailed breakdown:**
- Deepest recursion: N levels
- No additional data structures
- Total stack space: O(N)

<br>

---

## Why is 2^N - 1 Optimal?

**Proof by Contradiction:**

Assume we can do it in fewer moves.

**Observation:** To move the largest disk from A to C:
- All N-1 smaller disks must be on rod B (not on A or C)
- This requires at least 2^(N-1) - 1 moves

**After moving largest disk:**
- Need to move N-1 disks from B to C
- This requires at least 2^(N-1) - 1 moves

**Total:**
```
Minimum = (2^(N-1) - 1) + 1 + (2^(N-1) - 1)
        = 2 × 2^(N-1) - 1
        = 2^N - 1
```

**Conclusion:** 2^N - 1 is both necessary and sufficient!

<br>

---

## Variations

### Variation 1: Count Moves Only
```cpp
int countMoves(int n) {
    if (n == 1) return 1;
    return 2 * countMoves(n - 1) + 1;
}
// Or simply: return (1 << n) - 1;  // 2^n - 1
```

### Variation 2: Iterative Solution
```cpp
// Using binary representation
// For n disks, iterate from 1 to 2^n - 1
// Bit pattern determines which disk to move
```

### Variation 3: 4 Rods (Frame-Stewart Algorithm)
```cpp
// With 4 rods, fewer moves possible
// T(n) ≈ O(2^(n/2)) instead of O(2^n)
```

<br>

---

## Practical Insights

**Legend:**
- Brahma temple has 64 golden disks
- Priests move one disk per second
- World ends when complete
- Time: 2^64 - 1 seconds ≈ 585 billion years!

**Real Applications:**
1. **Backup Rotation:** Disk backup strategies
2. **Puzzle Games:** Classic recursive puzzle
3. **Algorithm Teaching:** Perfect recursion example
4. **Compiler Optimization:** Register allocation
5. **Network Routing:** Packet switching

<br>

---

## Key Takeaways

1. **Perfect Recursion Example:** Clear base case and recursive structure
2. **Exponential Growth:** Demonstrates why exponential algorithms are impractical
3. **Optimal Solution:** Proves recursive solution is optimal
4. **Divide & Conquer:** Classic example of breaking problem into subproblems
5. **Mathematical Beauty:** Elegant solution to complex problem

<br>

---

## Interview Tips

1. **Draw for N=2 or N=3:** Visualize the moves
2. **Explain the Three Steps:** Move N-1, move largest, move N-1
3. **Derive Recurrence:** T(n) = 2T(n-1) + 1
4. **Prove Optimality:** Show why fewer moves impossible
5. **Discuss Complexity:** O(2^n) time, O(n) space

<br>
<br>

---

```code```
