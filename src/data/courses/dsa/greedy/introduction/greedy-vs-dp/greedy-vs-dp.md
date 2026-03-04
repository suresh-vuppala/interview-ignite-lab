Understand when to use Greedy algorithms versus Dynamic Programming to solve optimization problems.

<br>

---

## Greedy Choice Property

A problem has greedy choice property if:
- Making locally optimal choice at each step leads to global optimum
- Choice doesn't depend on future subproblems
- Once made, choice is never reconsidered

**Example:** Activity Selection
- Greedy choice: Always pick activity with earliest end time
- This local choice guarantees global optimum (maximum activities)

<br>

---

## When to Use Greedy

**Characteristics:**
1. Problem has optimal substructure
2. Greedy choice property holds
3. No need to reconsider previous choices
4. Local optimum leads to global optimum

**Examples:**
- Activity Selection
- Huffman Coding
- Dijkstra's Shortest Path
- Minimum Spanning Tree (Kruskal's, Prim's)
- Fractional Knapsack

**Advantages:**
- Faster: Usually O(n log n) or O(n)
- Less space: O(1) or O(n)
- Simpler to implement

<br>

---

## When to Use Dynamic Programming

**Characteristics:**
1. Overlapping subproblems exist
2. Need to consider all possibilities
3. Greedy choice doesn't guarantee optimum
4. Must explore multiple paths

**Examples:**
- 0/1 Knapsack (can't use greedy)
- Longest Common Subsequence
- Matrix Chain Multiplication
- Edit Distance
- Coin Change (minimum coins)

**Advantages:**
- Guarantees optimal solution
- Works when greedy fails
- Handles complex dependencies

<br>

---

## Comparison Example

**Problem:** Coin Change - Minimum coins to make amount

**Greedy Approach:**
- Always pick largest coin ≤ remaining amount
- Coins = [1, 5, 10, 25], Amount = 30
- Greedy: 25 + 5 = 2 coins ✓ (works)
- Coins = [1, 3, 4], Amount = 6
- Greedy: 4 + 1 + 1 = 3 coins ✗ (wrong, optimal is 3 + 3 = 2 coins)

**DP Approach:**
- Try all possibilities, memoize results
- Always finds optimal solution
- Slower but correct for all coin systems

<br>

---

## Decision Framework

**Use Greedy if:**
- Can prove greedy choice property
- Local optimum = global optimum
- No need to backtrack
- Speed is critical

**Use DP if:**
- Greedy doesn't work (counterexample exists)
- Need to explore all possibilities
- Overlapping subproblems present
- Correctness > speed

```code```

<br>

### Complexity Comparison

**Greedy Algorithms:**
- Time: Usually O(n log n) due to sorting, or O(n) for single pass
- Space: O(1) to O(n)
- Fast but not always correct

**Dynamic Programming:**
- Time: Usually O(n²) or O(n × m) for 2D DP
- Space: O(n) to O(n × m) for memoization
- Slower but guarantees optimal solution

**Key Insight:**
- Greedy is optimization of DP when greedy choice property holds
- Always try greedy first, fall back to DP if greedy fails
- Prove correctness before using greedy in production

> **Greedy:** Fast, simple, but requires proof of correctness
> **DP:** Slower, complex, but always finds optimal solution when applicable

<br>
<br>

---