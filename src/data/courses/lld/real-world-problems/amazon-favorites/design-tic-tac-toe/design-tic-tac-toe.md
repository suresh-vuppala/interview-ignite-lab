# Design Tic-Tac-Toe

Design a flexible Tic-Tac-Toe game that supports different board sizes, player types (human, AI), and win detection.

<br>

---

## Requirements

### Main Requirements
1. **N×N board** — configurable size (default 3×3)
2. **Two players** — alternate turns
3. **Win detection** — row, column, or diagonal
4. **Draw detection** — board full with no winner
5. **Input validation** — occupied cell, out of bounds
6. **Display board** after each move

### Extended Requirements
1. AI player (random or minimax)
2. Undo last move
3. Game history / replay

<br>

---

## Core Entities

```
Game
├─ board: Board
├─ players: Player[2]
├─ currentTurn: int
├─ play(): void (game loop)

Board
├─ grid: char[][]
├─ size: int
├─ placeMove(row, col, symbol): boolean
├─ checkWin(symbol): boolean
├─ isFull(): boolean

Player (interface)
├── HumanPlayer — reads from input
├── AIPlayer — random or minimax strategy

WinChecker
├─ checkRows(), checkCols(), checkDiagonals()
```

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Strategy** | Player types (Human, AI) | Different move selection logic |
| **Factory** | Create players by type | Decouple creation |

<br>

---

## Interview Tips

- O(1) win check: track row/col/diagonal sums (increment for X, decrement for O)
- If sum = N → X wins; if sum = -N → O wins
- Discuss extensibility: larger boards, more players, different win conditions
