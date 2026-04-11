Reverse a string using stack data structure.

<br>

> Input:
> s = "hello"

> Output:
> "olleh"

> Explanation:
> Stack process:
> - Push 'h' → stack = ['h']
> - Push 'e' → stack = ['h', 'e']
> - Push 'l' → stack = ['h', 'e', 'l']
> - Push 'l' → stack = ['h', 'e', 'l', 'l']
> - Push 'o' → stack = ['h', 'e', 'l', 'l', 'o']
> - Pop 'o', Pop 'l', Pop 'l', Pop 'e', Pop 'h'
> - Result: "olleh"

<br>


---

## Constraints

- `0 ≤ s.length ≤ 10⁵`
- `s consists of printable ASCII characters`

<br>

---

## All Possible Edge Cases

1. **Empty string:** '' → ''
2. **Single character:** 'a' → 'a'
3. **Palindrome:** 'racecar' → 'racecar'
4. **Spaces:** 'hello world' → 'dlrow olleh'
5. **All same characters:** 'aaaa' → 'aaaa'

<br>

---

## Solution: Stack-Based Reversal

Use stack's LIFO property to reverse:
1. Push all characters onto stack
2. Pop all characters to build reversed string
3. Stack naturally reverses order

**Key insight:** Stack's LIFO (Last In First Out) automatically reverses order.



<br>

### Time Complexity Analysis

**Two Passes: O(n)**
- First pass: Push n characters to stack → O(n)
- Second pass: Pop n characters from stack → O(n)
- Total: O(n) + O(n) = O(2n) = O(n)

**Why O(n)?**
- Must process each character exactly twice
- Once for push, once for pop
- Both operations are O(1)

**Space Complexity: O(n)**
- Stack stores all n characters
- Result string also needs O(n) space
- Total: O(n) + O(n) = O(2n) = O(n)

> **Time Complexity:** O(n) - process each character twice
> **Space Complexity:** O(n) - stack holds all characters

<br>
<br>

---

---

```code```
