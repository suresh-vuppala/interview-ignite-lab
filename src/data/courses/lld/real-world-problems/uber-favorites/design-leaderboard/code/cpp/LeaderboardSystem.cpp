// ===========================================================================
// DESIGN: Leaderboard (Top K) — Low Level Design
// Key: Dual-map (HashMap + TreeMap) for O(logN) operations
// ===========================================================================
// FR: addScore, top(K), reset, getPlayerRank
// PLANTUML: Leaderboard { -playerScores:HashMap -scoreBoard:TreeMap(desc) }

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Leaderboard {
    map<int, int> playerScores;                    // playerId -> score
    map<int, set<int>, greater<int> > scoreBoard;  // score(desc) -> playerIds
public:
    void addScore(int playerId, int score) {
        int oldScore = playerScores.count(playerId) ? playerScores[playerId] : 0;
        // Remove from old position
        if (oldScore > 0) {
            scoreBoard[oldScore].erase(playerId);
            if (scoreBoard[oldScore].empty()) scoreBoard.erase(oldScore);
        }
        // Add to new position
        int newScore = oldScore + score;
        playerScores[playerId] = newScore;
        scoreBoard[newScore].insert(playerId);
        cout << "  Player " << playerId << ": +" << score << " = " << newScore << endl;
    }

    int top(int K) {
        int total = 0, count = 0;
        for (map<int,set<int>,greater<int> >::iterator it = scoreBoard.begin(); it != scoreBoard.end() && count < K; ++it) {
            int take = min((int)it->second.size(), K - count);
            total += it->first * take;
            count += take;
        }
        return total;
    }

    void reset(int playerId) {
        if (!playerScores.count(playerId)) return;
        int score = playerScores[playerId];
        scoreBoard[score].erase(playerId);
        if (scoreBoard[score].empty()) scoreBoard.erase(score);
        playerScores[playerId] = 0;
        cout << "  Reset player " << playerId << endl;
    }

    int getPlayerRank(int playerId) {
        if (!playerScores.count(playerId)) return -1;
        int playerScore = playerScores[playerId];
        int rank = 1;
        for (map<int,set<int>,greater<int> >::iterator it = scoreBoard.begin(); it != scoreBoard.end(); ++it) {
            if (it->first <= playerScore) break;
            rank += it->second.size();
        }
        return rank;
    }
};

int main() {
    cout << "============================================\n  Leaderboard — LLD Demo\n============================================" << endl;
    Leaderboard lb;
    lb.addScore(1, 50); lb.addScore(2, 80); lb.addScore(3, 50); lb.addScore(4, 120);
    cout << "  Top 2 sum: " << lb.top(2) << endl;
    cout << "  Player 1 rank: " << lb.getPlayerRank(1) << endl;
    cout << "  Player 4 rank: " << lb.getPlayerRank(4) << endl;
    lb.addScore(1, 100);  // 1 now has 150
    cout << "  After update — Top 2: " << lb.top(2) << endl;
    cout << "  Player 1 rank: " << lb.getPlayerRank(1) << endl;
    lb.reset(4);
    cout << "  After reset 4 — Top 3: " << lb.top(3) << endl;
    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: Dual-map: HashMap(O(1) lookup) + TreeMap(sorted order)
// PATTERNS: Composite data structure (two maps synced)
// PRACTICES: O(logN) add/rank, O(K) top query, tie handling
