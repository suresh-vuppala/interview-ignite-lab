# Design a Leaderboard (Top K)

Design a real-time leaderboard system that supports score updates and efficient top-K queries.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **addScore(playerId, score)** — add to player's cumulative score
2. **top(K)** — return sum of top K player scores
3. **reset(playerId)** — reset player's score to 0
4. **getPlayerRank(playerId)** — return player's current rank (1-indexed)
5. **getPlayerScore(playerId)** — return player's total score

### Extended Requirements (If Time Permits)

1. Leaderboard by category (daily, weekly, all-time)
2. Percentile rank (top 10%, top 25%)
3. Nearby players (show 5 above and 5 below current player)
4. Historical leaderboard snapshots
5. Team leaderboard (aggregate team member scores)
6. Anti-cheat: detect and flag suspicious score jumps

<br>

---

## Constraints

- Players: up to 1 million
- Scores: non-negative integers, max 10^9
- addScore: O(log N) per operation
- top(K): O(K log N) per query
- getPlayerRank: O(log N) per query
- Thread-safe for concurrent score updates

<br>

---

## Identify Primary Actors

1. **Game Server** — reports score changes
   - Actions: addScore when player completes action, reset on new season

2. **Player** — views leaderboard
   - Actions: check rank, view top-K, see nearby players

3. **Admin** — manages leaderboard
   - Actions: reset all scores, ban players, configure categories

<br>

---

## Core Entities

### 1. Leaderboard
- **Attributes**: playerScores: Map<playerId, score>, scoreBoard: TreeMap<score, Set<playerId>>
- **Methods**: addScore(), top(), reset(), getPlayerRank(), getPlayerScore()

### 2. Player Entry
- **Attributes**: playerId, totalScore, lastUpdated
- **Responsibilities**: Track individual player state

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Leaderboard | stores | playerScores (HashMap) | Composition (◆) |
| Leaderboard | maintains | scoreBoard (TreeMap) | Composition (◆) |
| playerScores | maps | playerId → score | Association |
| scoreBoard | maps | score → Set<playerId> | Association |

<br>

---

## Relationships Diagram (Textual UML)

```
  Leaderboard
  -playerScores: HashMap<playerId, score>      ← O(1) lookup
  -scoreBoard: TreeMap<score, Set<playerId>>   ← sorted by score desc
  +addScore(playerId, score): void
  +top(K): int
  +reset(playerId): void
  +getPlayerRank(playerId): int

  Dual-Map Approach:
  ┌──────────────────────┐
  │ HashMap (fast lookup) │    playerScores: {Alice:500, Bob:300, Carol:500}
  └──────────┬───────────┘
             │ sync
  ┌──────────▼───────────┐
  │ TreeMap (sorted order)│    scoreBoard: {500:[Alice,Carol], 300:[Bob]}
  └──────────────────────┘    (descending order)
```

<br>

---

## Design Patterns Used

### 1. **Dual-Map Pattern** (Composite Data Structure)
- **Where**: HashMap for O(1) player lookup + TreeMap for sorted order
- **Why**: Neither map alone provides both O(1) lookup AND sorted traversal
- **Benefit**: addScore is O(log N), top(K) is O(K), getPlayerRank is O(log N)

### 2. **Strategy Pattern** (extended)
- **Where**: Different ranking strategies (dense rank, competition rank, ordinal rank)
- **Why**: Different games use different ranking systems

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **synchronized** on addScore, reset — both modify two maps atomically
- **TreeMap iteration** for top(K) — snapshot or lock during iteration
- **Alternative**: `ConcurrentSkipListMap` for lock-free sorted map (but harder dual-map sync)

### Race Conditions Handled
- **Two servers update same player simultaneously**: `synchronized(this)` ensures atomic update of both maps
- **top(K) during addScore**: Read-write lock — multiple top(K) readers, exclusive addScore writers
- **Reset while addScore**: Same lock, atomic operation

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **K > total players** — return sum of ALL player scores
2. **Player not found** — return 0 for score, -1 for rank
3. **Tie scores** — multiple players at same rank; top(K) counts by player, not by unique score
4. **Reset non-existent player** — no-op
5. **addScore with 0** — valid but no-op
6. **Negative score after reset** — scores are non-negative, floor at 0
7. **Empty leaderboard** — top(K) returns 0
8. **All players same score** — all share rank 1

### Error Handling Strategy
- **InvalidScoreException**: Negative score value
- **InvalidKException**: K ≤ 0
- **PlayerNotFoundException**: For getPlayerRank — return -1 or throw

<br>

---

## Implementation

```code```
