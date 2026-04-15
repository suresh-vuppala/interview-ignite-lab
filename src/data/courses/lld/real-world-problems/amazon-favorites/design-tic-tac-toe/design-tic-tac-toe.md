# Design Tic-Tac-Toe

Design a flexible Tic-Tac-Toe game supporting configurable board sizes, different player types, and efficient win detection.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **N×N board** — configurable size (default 3×3)
2. **Two players** — alternate turns, each with a symbol (X, O)
3. **Win detection** — row, column, or diagonal completion
4. **Draw detection** — board full with no winner
5. **Input validation** — reject occupied cells, out-of-bounds moves
6. **Display board** — show current state after each move

### Extended Requirements (If Time Permits)

1. AI player (random moves or Minimax algorithm)
2. Undo last move
3. Game history / replay
4. Tournament mode (best of 3/5)
5. Custom symbols (beyond X and O)
6. Variable win length (e.g., 5-in-a-row on a 10×10 board)

<br>

---

## Constraints

- Board size: 3×3 to 20×20
- Players: exactly 2
- Symbols: single character, unique per player
- Win condition: N-in-a-row for N×N board (default)
- Move format: (row, column), 0-indexed
- Empty cell represented by space character

<br>

---

## Identify Primary Actors

1. **Player** (Human or AI) — makes moves on the board
   - Actions: select cell, view board, see game result

2. **Game** — orchestrates the game loop
   - Actions: alternate turns, validate moves, check win/draw, announce result

<br>

---

## Core Entities

### 1. Game
- **Attributes**: board: Board, players: Player[2], currentTurn: int
- **Responsibilities**: Game loop, alternate turns, announce winner/draw

### 2. Board
- **Attributes**: grid: char[][], size: int, movesCount: int
- **Attributes (O(1) win check)**: rowSums[], colSums[], diagSum, antiDiagSum
- **Responsibilities**: Place moves, validate moves, check win/draw, display

### 3. Player (Interface — Strategy Pattern)
- **Methods**: getName(), getSymbol(), getMove(board): int[]
- **Implementations**: HumanPlayer (reads input), AIPlayer (random or minimax)

### 4. WinChecker (embedded in Board)
- **Attributes**: rowSums, colSums, diagSum, antiDiagSum
- **Responsibilities**: O(1) win detection using sum tracking

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Game | has | Board | Composition (◆) |
| Game | has | Player[2] | Aggregation (◇) |
| HumanPlayer | implements | Player | Implementation |
| AIPlayer | implements | Player | Implementation |
| Board | uses | WinChecker (internal) | Composition (◆) |

<br>

---

## Relationships Diagram (Textual UML)

```
  Game
  -board: Board ◆
  -players: Player[2] ◇
  -currentTurn: int
  +play(): void (game loop)
       │
       ├──◆──→ Board
       │        -grid: char[][]
       │        -rowSums[], colSums[]
       │        -diagSum, antiDiagSum
       │        +placeMove(r,c,symbol): boolean
       │        +checkWin(symbol): boolean ← O(1)!
       │        +isFull(): boolean
       │        +display()
       │
       └──◇──→ Player (interface)
                +getName(), +getSymbol()
                +getMove(board): int[row,col]
                     △
                ┌────┴────┐
           HumanPlayer  AIPlayer
           (Scanner)    (Random/Minimax)
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: Player interface with HumanPlayer and AIPlayer implementations
- **Why**: Different move-selection strategies — human reads input, AI computes
- **Benefit**: Add new player types (NetworkPlayer, MinimaxAI) without changing Game class

### 2. **Template Method** (in Game.play())
- **Where**: Game loop follows fixed skeleton: display → getMove → validate → checkWin → switchTurn
- **Why**: Algorithm structure is fixed, but move-getting step varies by player type
- **Benefit**: Game logic doesn't change when player types change

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Single game instance**: Turn-based game is inherently sequential
- **Network multiplayer**: If extended to network play, synchronize board state updates
- **AI computation**: Run Minimax in separate thread, timeout after N seconds

### Race Conditions Handled
- **Two network players submit move simultaneously**: Server validates turn order, reject out-of-turn
- **AI timeout**: Force random move if Minimax exceeds time limit

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Cell already occupied** — reject move, prompt "Try again"
2. **Out-of-bounds move** — reject, show valid range
3. **First move** — always valid (empty board)
4. **Board completely full, no winner** — draw
5. **Win on last possible move** — check win before declaring draw
6. **1×1 board** — first player always wins immediately
7. **2×2 board** — no possible win with standard rules (all draws)
8. **AI vs AI** — game runs to completion without human input
9. **Undo on first move** — nothing to undo

### Error Handling Strategy
- **InvalidMoveException**: Cell occupied or out of bounds → prompt retry
- **GameOverException**: Move attempted after game ended
- **InvalidBoardSizeException**: Size < 1 or > 20

<br>

---

## Key Design Decision: O(1) Win Check

Instead of scanning all rows/columns/diagonals after each move (O(N²)), use **sum tracking**:

```
For X: value = +1, For O: value = -1

After each move at (row, col):
  rowSums[row] += value
  colSums[col] += value
  if (row == col) diagSum += value
  if (row + col == N-1) antiDiagSum += value

Win condition: any sum == +N (X wins) or -N (O wins)
```

This gives **O(1) win detection** per move instead of O(N²).

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Board with O(1) win detection, Strategy-based player types (Human + AI), and the game loop with validation.
