## Problem Statement
Design a search autocomplete system that returns top 3 matching sentences based on input prefix.

## Approach

### Trie with Frequency
- Each node stores:
  - Children map
  - List of (sentence, frequency) pairs
- On input character:
  - Traverse to current prefix node
  - Return top 3 sentences by frequency
- Time: O(L + K log K) where K=matching sentences

### Optimization
- Store only top 3 at each node
- Update during insertion
- Query becomes O(L)

## Complexity
- Insert: O(L*K) where K=top sentences
- Query: O(L)
- Space: O(N*L*K)

```code```
