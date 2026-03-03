# Shortest Unique Prefix

## Problem Statement
Find shortest unique prefix for each word that distinguishes it from all other words.

**Example**: ["zebra","dog","duck","dove"] → ["z","dog","du","dov"]

## Approach

### Trie with Prefix Count
- Build trie with prefix counts
- For each word:
  - Traverse until prefixCount = 1
  - That's the shortest unique prefix
- Time: O(N*L) for N words

## Complexity
- Build: O(N*L)
- Find prefixes: O(N*L)
- Total: O(N*L)

```code```
