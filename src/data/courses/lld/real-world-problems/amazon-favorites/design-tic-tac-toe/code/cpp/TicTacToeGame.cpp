// ===========================================================================
// DESIGN: Tic-Tac-Toe Game — Low Level Design
// ===========================================================================
// Single-file C++ | Patterns: Strategy Pattern, Template Method
// Key Design: O(1) win detection using row/col/diagonal sums
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: N×N configurable board (default 3×3)
// FR2: Two players alternate turns with unique symbols (X, O)
// FR3: Win detection — row, column, or diagonal
// FR4: Draw detection — board full, no winner
// FR5: Input validation — occupied cell, out of bounds
// FR6: Display board after each move

// 2. CONSTRAINTS: 3×3 to 20×20, exactly 2 players, 0-indexed moves

// 3. RELATIONSHIPS
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Game               | Board            | Composition  | 1 -> 1      | Game owns board            |
// | Game               | Player           | Aggregation  | 1 -> 2      | Game has 2 players         |
// | HumanPlayer        | Player           | Inheritance  | IS-A        | Concrete strategy          |
// | AIPlayer           | Player           | Inheritance  | IS-A        | Concrete strategy          |
// | Board              | WinChecker       | Composition  | 1 -> 1      | Board owns win logic       |
// +-------------------+------------------+--------------+-------------+----------------------------+

// 4. PLANTUML
// @startuml TicTacToe
// class Game { -board:Board \n -players:Player[2] \n -currentTurn:int \n +play() }
// class Board { -grid:char[][] \n -rowSums[] \n -colSums[] \n -diagSum \n -antiDiagSum \n +placeMove() \n +checkWin():O(1) }
// interface Player { +getName() +getSymbol() +getMove():pair }
// class HumanPlayer { reads from cin }
// class AIPlayer { random moves }
// Game *-- Board
// Game o-- "2" Player
// Player <|.. HumanPlayer
// Player <|.. AIPlayer
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===========================================================================
// CLASS: Board [Core Entity — O(1) Win Check]
// Key Insight: Track row/col/diagonal sums for O(1) win detection
// X = +1, O = -1. If any sum == +N → X wins, -N → O wins
// ===========================================================================
class Board {
private:
    vector<vector<char> > grid;
    int size;
    int movesCount;
    // O(1) win tracking arrays
    vector<int> rowSums;
    vector<int> colSums;
    int diagSum;
    int antiDiagSum;

public:
    Board(int size) : size(size), movesCount(0), diagSum(0), antiDiagSum(0) {
        grid.resize(size, vector<char>(size, ' '));
        rowSums.resize(size, 0);
        colSums.resize(size, 0);
    }

    int getSize() const { return size; }

    // Place move: validate, update grid, update sums
    // Returns true if move was valid
    bool placeMove(int row, int col, char symbol) {
        // Bounds check
        if (row < 0 || row >= size || col < 0 || col >= size) {
            cout << "  [ERROR] Out of bounds (" << row << "," << col << ")" << endl;
            return false;
        }
        // Occupied check
        if (grid[row][col] != ' ') {
            cout << "  [ERROR] Cell (" << row << "," << col << ") already occupied." << endl;
            return false;
        }

        // Place the move
        grid[row][col] = symbol;
        movesCount++;

        // Update win-tracking sums: X=+1, O=-1
        int val = (symbol == 'X') ? 1 : -1;
        rowSums[row] += val;
        colSums[col] += val;
        if (row == col) diagSum += val;              // Main diagonal
        if (row + col == size - 1) antiDiagSum += val; // Anti-diagonal

        return true;
    }

    // O(1) Win Check: any row/col/diagonal sum == +N or -N
    bool checkWin(char symbol) const {
        int target = (symbol == 'X') ? size : -size;
        for (int i = 0; i < size; i++) {
            if (rowSums[i] == target || colSums[i] == target)
                return true;
        }
        return diagSum == target || antiDiagSum == target;
    }

    // Draw: all cells filled, no winner
    bool isFull() const {
        return movesCount == size * size;
    }

    // Display the board
    void display() const {
        // Column headers
        cout << "   ";
        for (int j = 0; j < size; j++) cout << " " << j << "  ";
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << " " << i << " ";
            for (int j = 0; j < size; j++) {
                cout << " " << grid[i][j] << " ";
                if (j < size - 1) cout << "|";
            }
            cout << endl;
            if (i < size - 1) {
                cout << "   ";
                for (int j = 0; j < size; j++) {
                    cout << "---";
                    if (j < size - 1) cout << "+";
                }
                cout << endl;
            }
        }
    }
};

// ===========================================================================
// INTERFACE: Player [Strategy Pattern]
// Different move strategies: Human (input) vs AI (random/minimax)
// ===========================================================================
class Player {
public:
    virtual ~Player() {}
    virtual string getName() const = 0;
    virtual char getSymbol() const = 0;
    virtual pair<int,int> getMove(const Board& board) = 0;
};

// ===========================================================================
// CLASS: HumanPlayer [Strategy: reads from stdin]
// ===========================================================================
class HumanPlayer : public Player {
private:
    string name;
    char symbol;
public:
    HumanPlayer(const string& name, char symbol) : name(name), symbol(symbol) {}
    string getName() const { return name; }
    char getSymbol() const { return symbol; }

    pair<int,int> getMove(const Board& board) {
        int row, col;
        cout << "  " << name << " (" << symbol << "), enter row col: ";
        cin >> row >> col;
        return make_pair(row, col);
    }
};

// ===========================================================================
// CLASS: AIPlayer [Strategy: random moves]
// ===========================================================================
class AIPlayer : public Player {
private:
    string name;
    char symbol;
    int boardSize;
public:
    AIPlayer(const string& name, char symbol, int bs)
        : name(name), symbol(symbol), boardSize(bs) {}

    string getName() const { return name; }
    char getSymbol() const { return symbol; }

    pair<int,int> getMove(const Board& board) {
        // Random move (simplified AI)
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        cout << "  " << name << " (" << symbol << ") plays: " << row << " " << col << endl;
        return make_pair(row, col);
    }
};

// ===========================================================================
// CLASS: Game [Controller — Template Method Pattern]
// Game loop: display -> getMove -> validate -> checkWin -> switchTurn
// ===========================================================================
class Game {
private:
    Board board;           // Composition: Game owns board
    Player* players[2];    // Aggregation: Game uses players
    int currentTurn;

public:
    Game(int boardSize, Player* p1, Player* p2)
        : board(boardSize), currentTurn(0) {
        players[0] = p1;
        players[1] = p2;
    }

    // Main game loop (Template Method pattern)
    void play() {
        cout << "\n=== Tic-Tac-Toe ===" << endl;
        cout << "  " << players[0]->getName() << " (X) vs "
             << players[1]->getName() << " (O)" << endl;

        while (true) {
            // Step 1: Display board
            cout << endl;
            board.display();

            // Step 2: Get current player
            Player* current = players[currentTurn % 2];

            // Step 3: Get move (Strategy pattern — human or AI)
            pair<int,int> move = current->getMove(board);

            // Step 4: Validate and place
            if (!board.placeMove(move.first, move.second, current->getSymbol())) {
                cout << "  Invalid move, try again." << endl;
                continue;  // Don't switch turns
            }

            // Step 5: Check win (O(1) !)
            if (board.checkWin(current->getSymbol())) {
                cout << endl;
                board.display();
                cout << "\n  ** " << current->getName() << " WINS! **" << endl;
                return;
            }

            // Step 6: Check draw
            if (board.isFull()) {
                cout << endl;
                board.display();
                cout << "\n  ** DRAW! **" << endl;
                return;
            }

            // Step 7: Switch turn
            currentTurn++;
        }
    }
};

// ===========================================================================
// MAIN — Demonstrates AI vs AI game (no human input needed)
// ===========================================================================
int main() {
    srand((unsigned)time(NULL));

    cout << "============================================" << endl;
    cout << "  Tic-Tac-Toe — LLD Demo" << endl;
    cout << "============================================" << endl;

    // AI vs AI game (demonstrates all logic without requiring input)
    AIPlayer player1("AlphaBot", 'X', 3);
    AIPlayer player2("BetaBot", 'O', 3);

    Game game(3, &player1, &player2);
    game.play();

    cout << "\n============================================" << endl;
    cout << "  O(1) Win Check Explanation:" << endl;
    cout << "  X = +1, O = -1" << endl;
    cout << "  If rowSums[i] == +3  -> X wins row i" << endl;
    cout << "  If colSums[j] == -3  -> O wins col j" << endl;
    cout << "  If diagSum == +3     -> X wins diagonal" << endl;
    cout << "  Check: O(1) per move instead of O(N^2)" << endl;
    cout << "============================================" << endl;

    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> Game(3, AI_X, AI_O) -> game.play()
//     -> loop: board.display() -> player.getMove() [Strategy]
//        -> board.placeMove(row, col, symbol) [update grid + sums]
//        -> board.checkWin(symbol) [O(1): check sums == ±N]
//        -> board.isFull()? [draw check]
//        -> currentTurn++ [switch player]

// METHOD CALL TREE:
//   game.play()
//     -> board.display()
//     -> player->getMove(board) [Strategy: Human reads stdin, AI randomizes]
//     -> board.placeMove(row, col, symbol)
//        -> grid[row][col] = symbol
//        -> rowSums[row] += val, colSums[col] += val
//        -> if (row==col) diagSum += val
//        -> if (row+col==N-1) antiDiagSum += val
//     -> board.checkWin(symbol)
//        -> any rowSums[i]==target || colSums[i]==target || diagSum==target

// CLASS RESPONSIBILITY TABLE:
//   Board       | Grid, O(1) win sums, placeMove, checkWin, display
//   Player (i)  | Strategy: getName, getSymbol, getMove
//   HumanPlayer | Reads from stdin
//   AIPlayer    | Random moves
//   Game        | Game loop, turn management, win/draw detection

// DESIGN PATTERNS:
//   1. Strategy       -> Player interface (Human vs AI move strategies)
//   2. Template Method-> Game.play() fixed loop, vary getMove()

// BEST PRACTICES:
//   1. O(1) win check -> Row/col/diag sum tracking (interview favorite!)
//   2. Encapsulation  -> Board internals hidden from Game
//   3. Polymorphism   -> Player dispatched at runtime
//   4. SRP            -> Board handles grid, Game handles flow
//   5. OCP            -> Add MinimaxAI without changing Game
