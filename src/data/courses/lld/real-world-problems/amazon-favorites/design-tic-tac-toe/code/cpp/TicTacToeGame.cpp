#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Board {
    vector<vector<char>> grid;
    int sz, movesCount = 0;
    vector<int> rowSums, colSums;
    int diagSum = 0, antiDiagSum = 0;
public:
    Board(int size) : sz(size), grid(size, vector<char>(size, ' ')), rowSums(size, 0), colSums(size, 0) {}
    bool placeMove(int row, int col, char symbol) {
        if (row < 0 || row >= sz || col < 0 || col >= sz || grid[row][col] != ' ') return false;
        grid[row][col] = symbol; movesCount++;
        int val = (symbol == 'X') ? 1 : -1;
        rowSums[row] += val; colSums[col] += val;
        if (row == col) diagSum += val;
        if (row + col == sz - 1) antiDiagSum += val;
        return true;
    }
    bool checkWin(char symbol) const {
        int target = (symbol == 'X') ? sz : -sz;
        for (int i = 0; i < sz; i++) if (rowSums[i] == target || colSums[i] == target) return true;
        return diagSum == target || antiDiagSum == target;
    }
    bool isFull() const { return movesCount == sz * sz; }
    int getSize() const { return sz; }
    char getCell(int r, int c) const { return grid[r][c]; }
    void display() const {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) { cout << " " << grid[i][j] << " "; if (j < sz-1) cout << "|"; }
            cout << endl;
            if (i < sz-1) { for (int j = 0; j < sz*4-1; j++) cout << "-"; cout << endl; }
        }
    }
};

class Player {
public:
    virtual ~Player() = default;
    virtual string getName() const = 0;
    virtual char getSymbol() const = 0;
    virtual pair<int,int> getMove(const Board& board) = 0;
};

class HumanPlayer : public Player {
    string name; char symbol;
public:
    HumanPlayer(string n, char s) : name(move(n)), symbol(s) {}
    string getName() const override { return name; }
    char getSymbol() const override { return symbol; }
    pair<int,int> getMove(const Board&) override {
        int r, c; cout << name << " (" << symbol << "), enter row col: ";
        cin >> r >> c; return {r, c};
    }
};

class AIPlayer : public Player {
    string name; char symbol; int boardSize;
public:
    AIPlayer(string n, char s, int bs) : name(move(n)), symbol(s), boardSize(bs) { srand(time(0)); }
    string getName() const override { return name; }
    char getSymbol() const override { return symbol; }
    pair<int,int> getMove(const Board&) override { return {rand() % boardSize, rand() % boardSize}; }
};

class TicTacToeGame {
    Board board;
    vector<unique_ptr<Player>> players;
    int currentTurn = 0;
public:
    TicTacToeGame(int size, unique_ptr<Player> p1, unique_ptr<Player> p2) : board(size) {
        players.push_back(move(p1)); players.push_back(move(p2));
    }
    void play() {
        cout << "=== Tic-Tac-Toe ===" << endl;
        while (true) {
            board.display();
            auto& current = players[currentTurn % 2];
            auto [r, c] = current->getMove(board);
            if (!board.placeMove(r, c, current->getSymbol())) { cout << "Invalid move" << endl; continue; }
            if (board.checkWin(current->getSymbol())) { board.display(); cout << current->getName() << " wins!" << endl; return; }
            if (board.isFull()) { board.display(); cout << "Draw!" << endl; return; }
            currentTurn++;
        }
    }
};
