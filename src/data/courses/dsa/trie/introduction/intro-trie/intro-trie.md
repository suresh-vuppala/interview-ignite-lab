## Trie — Efficient Prefix-Based Operations

A trie (prefix tree) is a tree-like data structure where each node represents a character. Paths from root to nodes form prefixes, enabling O(L) lookup where L is the word length — independent of how many words are stored.

<br>

## When to Use a Trie

- "Find all words with **prefix**..." → Trie + DFS
- "**Autocomplete** system" → Trie with frequency counts
- "**Word search** in a grid" → Trie + backtracking
- "Find **maximum XOR**" → Binary trie
- "Count **distinct substrings**" → Suffix trie

<br>

## Trie vs Hash Set/Map

| Operation | Trie | Hash Set |
|-----------|------|----------|
| Search word | O(L) | O(L) average |
| Prefix search | O(L) ✅ | O(n×L) ❌ |
| Autocomplete | O(L + results) ✅ | O(n×L) ❌ |
| Space | More (pointers) | Less (flat) |

**Use trie when you need prefix-based operations.** Hash sets can't efficiently search by prefix.

<br>

## Module Sections

1. **Core operations** — Insert, search, prefix check, delete
2. **Prefix problems** — LCP, replace words, autocomplete, suggestions
3. **Trie + backtracking** — Word Search II, boggle board
4. **Binary trie** — Maximum XOR problems
5. **Advanced** — Compressed trie, ternary search tree, wildcards

<br>

---

```code```
