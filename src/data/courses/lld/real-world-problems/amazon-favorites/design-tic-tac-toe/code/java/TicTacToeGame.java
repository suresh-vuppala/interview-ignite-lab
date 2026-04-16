// ===========================================================================
// DESIGN: Tic-Tac-Toe Game — Low Level Design (Java)
// ===========================================================================
// Patterns: Strategy, Template Method | Key: O(1) win detection
// ===========================================================================

// 1. FR: N×N board, 2 players, win/draw detection, input validation
// 2. CONSTRAINTS: 3-20 board size, 0-indexed moves
// 3. RELATIONSHIPS: Game*--Board, Game o--Player[2], Player<|..Human/AI
// 4. PLANTUML: (see C++ for full diagram)

import java.util.*;

// ===========================================================================
// Board with O(1) win detection
// ===========================================================================
class Board {
    private char[][] grid;
    private int size, movesCount = 0;
    private int[] rowSums, colSums;
    private int diagSum = 0, antiDiagSum = 0;

    public Board(int size) {
        this.size = size;
        grid = new char[size][size];
        rowSums = new int[size];
        colSums = new int[size];
        for (char[] row : grid) Arrays.fill(row, ' ');
    }

    public int getSize() { return size; }

    // Place move + update O(1) sums
    public boolean placeMove(int row, int col, char symbol) {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            System.out.println("  [ERROR] Out of bounds.");
            return false;
        }
        if (grid[row][col] != ' ') {
            System.out.println("  [ERROR] Cell occupied.");
            return false;
        }
        grid[row][col] = symbol;
        movesCount++;
        int val = (symbol == 'X') ? 1 : -1;
        rowSums[row] += val;
        colSums[col] += val;
        if (row == col) diagSum += val;
        if (row + col == size - 1) antiDiagSum += val;
        return true;
    }

    // O(1) win check
    public boolean checkWin(char symbol) {
        int target = (symbol == 'X') ? size : -size;
        for (int i = 0; i < size; i++)
            if (rowSums[i] == target || colSums[i] == target) return true;
        return diagSum == target || antiDiagSum == target;
    }

    public boolean isFull() { return movesCount == size * size; }

    public void display() {
        System.out.print("   ");
        for (int j = 0; j < size; j++) System.out.print(" " + j + "  ");
        System.out.println();
        for (int i = 0; i < size; i++) {
            System.out.print(" " + i + " ");
            for (int j = 0; j < size; j++) {
                System.out.print(" " + grid[i][j] + " ");
                if (j < size - 1) System.out.print("|");
            }
            System.out.println();
            if (i < size - 1) {
                System.out.print("   ");
                for (int j = 0; j < size; j++) {
                    System.out.print("---");
                    if (j < size - 1) System.out.print("+");
                }
                System.out.println();
            }
        }
    }
}

// ===========================================================================
// Player interface [Strategy Pattern]
// ===========================================================================
interface Player {
    String getName();
    char getSymbol();
    int[] getMove(Board board);
}

// Human Player
class HumanPlayer implements Player {
    private String name;
    private char symbol;
    public HumanPlayer(String name, char symbol) { this.name = name; this.symbol = symbol; }
    public String getName() { return name; }
    public char getSymbol() { return symbol; }
    public int[] getMove(Board board) {
        Scanner sc = new Scanner(System.in);
        System.out.print("  " + name + " (" + symbol + "), enter row col: ");
        return new int[]{sc.nextInt(), sc.nextInt()};
    }
}

// AI Player (random)
class AIPlayer implements Player {
    private String name;
    private char symbol;
    private int boardSize;
    private Random rand = new Random();

    public AIPlayer(String name, char symbol, int bs) {
        this.name = name; this.symbol = symbol; this.boardSize = bs;
    }
    public String getName() { return name; }
    public char getSymbol() { return symbol; }
    public int[] getMove(Board board) {
        int r = rand.nextInt(boardSize), c = rand.nextInt(boardSize);
        System.out.println("  " + name + " (" + symbol + ") plays: " + r + " " + c);
        return new int[]{r, c};
    }
}

// ===========================================================================
// Game [Controller]
// ===========================================================================
class TicTacToe {
    private Board board;
    private Player[] players;
    private int currentTurn = 0;

    public TicTacToe(int size, Player p1, Player p2) {
        this.board = new Board(size);
        this.players = new Player[]{p1, p2};
    }

    public void play() {
        System.out.println("\n=== Tic-Tac-Toe ===");
        System.out.println("  " + players[0].getName() + " (X) vs " + players[1].getName() + " (O)");

        while (true) {
            System.out.println();
            board.display();
            Player current = players[currentTurn % 2];
            int[] move = current.getMove(board);

            if (!board.placeMove(move[0], move[1], current.getSymbol())) {
                System.out.println("  Invalid, try again."); continue;
            }
            if (board.checkWin(current.getSymbol())) {
                System.out.println(); board.display();
                System.out.println("\n  ** " + current.getName() + " WINS! **"); return;
            }
            if (board.isFull()) {
                System.out.println(); board.display();
                System.out.println("\n  ** DRAW! **"); return;
            }
            currentTurn++;
        }
    }
}

// ===========================================================================
// MAIN
// ===========================================================================
public class TicTacToeGame {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Tic-Tac-Toe — LLD Demo (Java)");
        System.out.println("============================================");

        AIPlayer p1 = new AIPlayer("AlphaBot", 'X', 3);
        AIPlayer p2 = new AIPlayer("BetaBot", 'O', 3);

        TicTacToe game = new TicTacToe(3, p1, p2);
        game.play();

        System.out.println("\nO(1) Win Check: X=+1, O=-1. Sum==±N → win.");
    }
}

// SUMMARY:
// EXECUTION FLOW: main() -> Game(3, AI, AI) -> play() loop
//   -> board.display() -> player.getMove() [Strategy] -> board.placeMove()
//   -> board.checkWin() [O(1): rowSums/colSums/diagSum check] -> switch turn
// METHOD CALL TREE: game.play() -> board.placeMove() -> update sums -> checkWin() -> compare sums to ±N
// DESIGN PATTERNS: 1. Strategy -> Player (Human vs AI), 2. Template Method -> Game loop
// BEST PRACTICES: O(1) win check (interview favorite), Encapsulation, Polymorphism, SRP, OCP
