#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <mutex>
using namespace std;

class Leaderboard {
    unordered_map<int, int> playerScores;         // playerId -> score
    map<int, set<int>, greater<int>> scoreBoard;  // score -> playerIds (descending)
    mutex mtx;
public:
    void addScore(int playerId, int score) {
        lock_guard<mutex> lock(mtx);
        int oldScore = playerScores.count(playerId) ? playerScores[playerId] : 0;
        int newScore = oldScore + score;
        
        if (oldScore > 0) {
            scoreBoard[oldScore].erase(playerId);
            if (scoreBoard[oldScore].empty()) scoreBoard.erase(oldScore);
        }
        playerScores[playerId] = newScore;
        scoreBoard[newScore].insert(playerId);
    }
    
    int top(int K) {
        lock_guard<mutex> lock(mtx);
        int total = 0, count = 0;
        for (auto& [score, players] : scoreBoard) {
            int take = min((int)players.size(), K - count);
            total += score * take;
            count += take;
            if (count >= K) break;
        }
        return total;
    }
    
    void reset(int playerId) {
        lock_guard<mutex> lock(mtx);
        if (!playerScores.count(playerId)) return;
        int score = playerScores[playerId];
        scoreBoard[score].erase(playerId);
        if (scoreBoard[score].empty()) scoreBoard.erase(score);
        playerScores[playerId] = 0;
    }
    
    int getPlayerRank(int playerId) {
        lock_guard<mutex> lock(mtx);
        if (!playerScores.count(playerId)) return -1;
        int playerScore = playerScores[playerId];
        int rank = 1;
        for (auto& [score, players] : scoreBoard) {
            if (score <= playerScore) break;
            rank += players.size();
        }
        return rank;
    }
};
