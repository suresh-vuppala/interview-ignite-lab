// Tic-Tac-Toe Game
import java.util.*;

class Board {
    private char[][] grid;
    private int size;
    private int movesCount = 0;
    // O(1) win check arrays
    private int[] rowSums, colSums;
    private int diagSum, antiDiagSum;
    
    public Board(int size) {
        this.size = size;
        grid = new char[size][size];
        rowSums = new int[size];
        colSums = new int[size];
        for (char[] row : grid) Arrays.fill(row, ' ');
    }
    
    public boolean placeMove(int row, int col, char symbol) {
        if (row < 0 || row >= size || col < 0 || col >= size) return false;
        if (grid[row][col] != ' ') return false;
        grid[row][col] = symbol;
        movesCount++;
        int val = (symbol == 'X') ? 1 : -1;
        rowSums[row] += val;
        colSums[col] += val;
        if (row == col) diagSum += val;
        if (row + col == size - 1) antiDiagSum += val;
        return true;
    }
    
    public boolean checkWin(char symbol) {
        int target = (symbol == 'X') ? size : -size;
        for (int i = 0; i < size; i++) {
            if (rowSums[i] == target || colSums[i] == target) return true;
        }
        return diagSum == target || antiDiagSum == target;
    }
    
    public boolean isFull() { return movesCount == size * size; }
    
    public void display() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(" " + grid[i][j] + " ");
                if (j < size - 1) System.out.print("|");
            }
            System.out.println();
            if (i < size - 1) System.out.println("-".repeat(size * 4 - 1));
        }
    }
}

interface Player {
    String getName();
    char getSymbol();
    int[] getMove(Board board);
}

class HumanPlayer implements Player {
    private String name;
    private char symbol;
    public HumanPlayer(String name, char symbol) { this.name = name; this.symbol = symbol; }
    public String getName() { return name; }
    public char getSymbol() { return symbol; }
    public int[] getMove(Board board) {
        Scanner sc = new Scanner(System.in);
        System.out.print(name + " (" + symbol + "), enter row col: ");
        return new int[]{sc.nextInt(), sc.nextInt()};
    }
}

class AIPlayer implements Player {
    private String name;
    private char symbol;
    private Random rand = new Random();
    private int boardSize;
    public AIPlayer(String name, char symbol, int boardSize) {
        this.name = name; this.symbol = symbol; this.boardSize = boardSize;
    }
    public String getName() { return name; }
    public char getSymbol() { return symbol; }
    public int[] getMove(Board board) {
        int r, c;
        do { r = rand.nextInt(boardSize); c = rand.nextInt(boardSize); }
        while (!board.placeMove(r, c, symbol)); // Try until valid (hacky for demo)
        return new int[]{r, c};
    }
}

class TicTacToeGame {
    private Board board;
    private Player[] players;
    private int currentTurn = 0;
    
    public TicTacToeGame(int size, Player p1, Player p2) {
        this.board = new Board(size);
        this.players = new Player[]{p1, p2};
    }
    
    public void play() {
        System.out.println("=== Tic-Tac-Toe ===");
        while (true) {
            board.display();
            Player current = players[currentTurn % 2];
            int[] move = current.getMove(board);
            if (!board.placeMove(move[0], move[1], current.getSymbol())) {
                System.out.println("Invalid move, try again.");
                continue;
            }
            if (board.checkWin(current.getSymbol())) {
                board.display();
                System.out.println("🏆 " + current.getName() + " wins!");
                return;
            }
            if (board.isFull()) {
                board.display();
                System.out.println("🤝 Draw!");
                return;
            }
            currentTurn++;
        }
    }
}
