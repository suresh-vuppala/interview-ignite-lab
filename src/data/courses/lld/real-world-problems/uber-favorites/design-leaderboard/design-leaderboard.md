# Design a Leaderboard (Top K)

Design a real-time leaderboard system that supports adding/updating scores and querying the top K players.

<br>

---

## Requirements

### Main Requirements
1. **addScore(playerId, score)** — add to player's total score
2. **top(K)** — return sum of top K scores
3. **reset(playerId)** — reset player's score to 0
4. **getPlayerRank(playerId)** — return player's current rank

<br>

---

## Approaches

### Approach 1: HashMap + Sort — O(N log N) per top query
### Approach 2: HashMap + TreeMap — O(log N) per operation

TreeMap keeps scores sorted. HashMap gives O(1) player lookup. Combine both.

<br>

---

## Core Design

```
Leaderboard
├─ scores: Map<Integer, Integer> — playerId → score
├─ sortedScores: TreeMap<Integer, Set<Integer>> — score → playerIds
├─ addScore(playerId, score): void
├─ top(K): int
├─ reset(playerId): void
```

<br>

---

## Interview Tips

- Two-map approach: HashMap for O(1) lookup, TreeMap for sorted order
- top(K): iterate TreeMap in descending order
- Handle ties: multiple players with same score
- Thread safety for concurrent score updates
