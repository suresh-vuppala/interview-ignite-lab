In a party of N people, a celebrity is someone who is known by everyone but doesn't know anyone. Given a square matrix `M` where `M[i][j] = 1` means person i knows person j, find the celebrity.

Return the celebrity's index, or -1 if no celebrity exists.

<br>

> Input:
> M = [[0, 1, 0], [0, 0, 0], [0, 1, 0]]

> Output:
> 1

> Explanation:
> The matrix represents:
> - Person 0 knows person 1
> - Person 1 knows nobody
> - Person 2 knows person 1
> 
> **Person 1 is the celebrity:**
> - Everyone (0 and 2) knows person 1
> - Person 1 knows nobody
> 
> **Verification:**
> - Row 1: All zeros (knows nobody) ✓
> - Column 1: All ones except diagonal (everyone knows them) ✓

<br>


---

## Constraints

- `2 ≤ n ≤ 1000`
- `Matrix M[i][j] is 0 or 1`
- `M[i][i] = 0 (nobody knows themselves)`

<br>

---

## All Possible Edge Cases

1. **No celebrity exists:** Everyone knows someone or someone doesn't know them
2. **Celebrity is first person:** Index 0
3. **Celebrity is last person:** Index n-1
4. **Two people, one celebrity:** Minimum case
5. **Everyone knows everyone:** No celebrity (celebrity can't know anyone)
6. **Nobody knows anyone:** No celebrity (celebrity must be known by all)

<br>

---

## Solution: Stack Elimination + Verification

**Two-pass approach:**

**Pass 1 - Find candidate using stack:**
1. Push all people (0 to n-1) to stack
2. While stack has 2+ people:
   - Pop two people A and B
   - If A knows B: A can't be celebrity, push B
   - If A doesn't know B: B can't be celebrity, push A
3. Last person in stack is potential celebrity

**Pass 2 - Verify candidate:**
1. Check candidate's row: All zeros?
2. Check candidate's column: All ones (except diagonal)?

**Key insight:** Each comparison eliminates one non-celebrity.



<br>

### Time Complexity Analysis

**Overall: O(n)**

**Pass 1 - Find Candidate: O(n)**
- Push n people: O(n)
- Pop pairs until one remains: n-1 comparisons = O(n)
- Each comparison eliminates one person

**Pass 2 - Verify Candidate: O(n)**
- Check row: n elements = O(n)
- Check column: n elements = O(n)
- Total: O(2n) = O(n)

**Why stack is optimal?**
- Eliminates non-celebrities efficiently
- Each comparison reduces candidates by 1
- No need to check all pairs (would be O(n²))

**Space Complexity: O(n)**
- Stack holds at most n people
- Can optimize to O(1) using two pointers instead of stack

**Alternative approach:**
- Two pointers: O(n) time, O(1) space
- Stack approach: More intuitive, same time complexity

> **Time Complexity:** O(n) - two linear passes
> **Space Complexity:** O(n) - stack storage

<br>
<br>

---

---

```code```
