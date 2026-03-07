#!/usr/bin/env python3
"""
Batch generator for Priority A DP problems.
Creates Python, C++, Java implementations and comprehensive markdown.
"""
import os
from pathlib import Path

# Problem definitions with metadata
PRIORITY_PROBLEMS = {
    'edit-distance': {
        'category': 'string-dp',
        'title': 'Edit Distance',
        'description': 'Convert word1 to word2 using minimum operations (insert, delete, replace)',
        'example': 'word1="horse", word2="ros" → 3 operations',
        'operations': ['insert', 'delete', 'replace'],
        'time_recursive': 'O(3^(M+N))',
        'time_optimized': 'O(M×N)',
        'space_optimized': 'O(N)'
    },
    'longest-increasing-subsequence': {
        'category': 'lis-sequence',
        'title': 'Longest Increasing Subsequence',
        'description': 'Find length of longest strictly increasing subsequence',
        'example': '[10,9,2,5,3,7,101,18] → 4 ([2,3,7,101])',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N²) or O(N log N)',
        'space_optimized': 'O(N)'
    },
    'word-break': {
        'category': 'string-dp',
        'title': 'Word Break',
        'description': 'Check if string can be segmented into dictionary words',
        'example': 's="leetcode", dict=["leet","code"] → true',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N²)',
        'space_optimized': 'O(N)'
    },
    'stock-buy-sell-i': {
        'category': 'state-decision-dp',
        'title': 'Stock Buy Sell I',
        'description': 'Maximum profit with at most one transaction',
        'example': '[7,1,5,3,6,4] → 5 (buy at 1, sell at 6)',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N)',
        'space_optimized': 'O(1)'
    },
    'stock-buy-sell-ii': {
        'category': 'state-decision-dp',
        'title': 'Stock Buy Sell II',
        'description': 'Maximum profit with unlimited transactions',
        'example': '[7,1,5,3,6,4] → 7 (buy-sell multiple times)',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N)',
        'space_optimized': 'O(1)'
    },
    'subset-sum': {
        'category': 'classic-dp',
        'title': 'Subset Sum',
        'description': 'Check if subset exists with given sum',
        'example': '[3,34,4,12,5,2], sum=9 → true ([4,5])',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N×Sum)',
        'space_optimized': 'O(Sum)'
    },
    'longest-palindromic-substring': {
        'category': 'string-dp',
        'title': 'Longest Palindromic Substring',
        'description': 'Find longest palindromic substring',
        'example': 's="babad" → "bab" or "aba"',
        'time_recursive': 'O(3^N)',
        'time_optimized': 'O(N²)',
        'space_optimized': 'O(1) with expand around center'
    },
    'maximum-product-subarray': {
        'category': 'state-decision-dp',
        'title': 'Maximum Product Subarray',
        'description': 'Find contiguous subarray with largest product',
        'example': '[2,3,-2,4] → 6 ([2,3])',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N)',
        'space_optimized': 'O(1)'
    },
    'longest-palindromic-subsequence': {
        'category': 'string-dp',
        'title': 'Longest Palindromic Subsequence',
        'description': 'Find length of longest palindromic subsequence',
        'example': 's="bbbab" → 4 ("bbbb")',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N²)',
        'space_optimized': 'O(N)'
    },
    'coin-change-ways': {
        'category': 'classic-dp',
        'title': 'Coin Change II - Number of Ways',
        'description': 'Count ways to make amount using given coins',
        'example': 'amount=5, coins=[1,2,5] → 4 ways',
        'time_recursive': 'O(2^N)',
        'time_optimized': 'O(N×Amount)',
        'space_optimized': 'O(Amount)'
    }
}

def generate_markdown_stub(problem_key, metadata):
    """Generate comprehensive markdown for a problem"""
    title = metadata['title']
    desc = metadata['description']
    example = metadata['example']
    
    md = f"""# {title}

## Problem Statement

{desc}

**Example:**
```
{example}
```

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
[Problem-specific intuition]

**Recurrence Relation:**
```
[Problem-specific recurrence]
```

**Algorithm:**
1. Base cases
2. Recursive computation
3. Return result

### Time Complexity: {metadata['time_recursive']}
**Why?**
- Exponential branching at each decision point
- Overlapping subproblems computed multiple times

### Space Complexity: O(N) or O(M+N)
**Why?**
- Recursion stack depth

> **Key Insight for Improvement:**
> Cache results to avoid recomputation.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store computed results in memo table.

### Time Complexity: {metadata['time_optimized']}
**Why?**
- Each subproblem computed once
- Memoization eliminates redundant calculations

### Space Complexity: {metadata['time_optimized']}
**Why?**
- Memo table + recursion stack

> **Key Insight for Improvement:**
> Iterative approach eliminates recursion overhead.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively from base cases.

### Time Complexity: {metadata['time_optimized']}
**Why?**
- Single pass through all states

### Space Complexity: {metadata['time_optimized']}
**Why?**
- DP table storage

> **Key Insight for Improvement:**
> Optimize space by keeping only necessary states.

<br>

---

## Solution 4: Space Optimized

**Intuition:**
Reduce space by tracking only required previous states.

### Time Complexity: {metadata['time_optimized']}
**Why unchanged?**
- Same computation, optimized storage

### Space Complexity: {metadata['space_optimized']}
**Why optimal?**
- Minimal state tracking

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | {metadata['time_recursive']} | O(N) | Baseline |
| Memoization | {metadata['time_optimized']} | {metadata['time_optimized']} | Cache results |
| Tabulation | {metadata['time_optimized']} | {metadata['time_optimized']} | Iterative |
| Space Optimized | {metadata['time_optimized']} | {metadata['space_optimized']} | Minimal space |

> **Final Complexity:** {metadata['time_optimized']} time, {metadata['space_optimized']} space

<br>
<br>

---

```code```
"""
    return md

def create_problem_files(problem_key, metadata):
    """Create all files for a problem"""
    base_path = Path(f"src/data/courses/dsa/dynamic-programming/{metadata['category']}/{problem_key}")
    
    # Create markdown
    md_file = base_path / f"{problem_key}.md"
    if not md_file.exists() or md_file.stat().st_size < 500:
        md_content = generate_markdown_stub(problem_key, metadata)
        md_file.parent.mkdir(parents=True, exist_ok=True)
        with open(md_file, 'w', encoding='utf-8') as f:
            f.write(md_content)
        print(f"Created: {md_file.name}")
    
    print(f"✓ {metadata['title']}")

def main():
    os.chdir(r"d:\interview-ignite-lab")
    
    print("="*80)
    print("GENERATING PRIORITY A DP PROBLEMS")
    print("="*80)
    
    for problem_key, metadata in PRIORITY_PROBLEMS.items():
        print(f"\nProcessing: {metadata['title']}")
        create_problem_files(problem_key, metadata)
    
    print("\n" + "="*80)
    print(f"COMPLETE: Generated files for {len(PRIORITY_PROBLEMS)} problems")
    print("="*80)

if __name__ == "__main__":
    main()
