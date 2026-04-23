## Stacks — Last In, First Out (LIFO)

A stack is a linear data structure where elements are added and removed from the **same end** (the top). Think of a stack of plates — you always add and remove from the top.

<br>

## Why Stacks Matter in Interviews

Stacks appear in **~10% of FAANG interviews**. Master these 5 patterns and most stack problems become mechanical.

<br>

## 🧠 The 5 Core Stack Patterns

### 1. Matching / Validation Pattern

**Idea:** Use stack to match pairs.

**When to use:** Brackets, tags, expressions

**Template:**
```cpp
if (opening) push
else {
    if (stack empty or mismatch) return false;
    pop
}
```

**Mental Model:** *"Every close must match the last open"*

**Examples:** Valid Parentheses, HTML tag matching

<br>

### 2. Monotonic Stack (Next Greater/Smaller)

**Idea:** Maintain stack in increasing/decreasing order.

**When to use:** Next greater/smaller element, range dominance problems

**Template:**
```cpp
while (!st.empty() && st.top() < current)
    st.pop();

st.push(current);
```

**Mental Model:** *"Remove useless elements when a better one comes"*

**Examples:** Next Greater Element, Daily Temperatures, Stock Span

**Time Complexity:** O(n) — each element pushed and popped at most once.

<br>

### 3. Contribution / Range Expansion

**Idea:** Each element contributes over a range.

**When to use:** Sum of subarray minimums, largest rectangle in histogram

**Template:**
```cpp
while (!st.empty() && height < st.top()) {
    compute area/contribution
    st.pop();
}
```

**Mental Model:** *"Pop when boundary breaks and calculate contribution"*

**Examples:** Largest Rectangle in Histogram, Sum of Subarray Minimums

<br>

### 4. Build / Undo (Simulation Stack)

**Idea:** Stack represents state or construction.

**When to use:** String building, undo operations

**Template:**
```cpp
if (condition)
    push/build
else
    pop/remove/merge
```

**Mental Model:** *"Stack = current state of construction"*

**Examples:** Remove Adjacent Duplicates, Simplify Path, Decode String

<br>

### 5. Nested Structure / Value Propagation

**Idea:** Handle nested blocks, compute value, pass upward.

**When to use:** Expressions, parentheses scoring, tree-like structures

**Template:**
```cpp
push new frame

on close:
    compute value
    if parent exists → add to parent
    else → add to result
```

**Mental Model:** *"Inner result flows to outer layer"*

**Examples:** Score of Parentheses, Basic Calculator, Decode String

<br>

## 🔥 Quick Pattern Recognition

| Pattern | Trigger |
|---------|-------------------------|
| Matching | pairs, validity |
| Monotonic | next greater/smaller |
| Contribution | range influence |
| Build/Undo | construct/remove |
| Nested | recursion-like structure |

<br>

## 🎯 Core Insight

```text
Stack = store unfinished work, process when condition breaks
```

<br>

## Key Problems by Difficulty

| Easy | Medium | Hard |
|------|--------|------|
| Valid Parentheses | Daily Temperatures | Largest Rectangle Histogram |
| Min Stack | Decode String | Maximal Rectangle |
| | Remove K Digits | Trapping Rain Water (stack approach) |

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
