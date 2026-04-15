#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Leaderboard {
    unordered_map<int, int> playerScores;  // playerId -> score
    map<int, set<int>, greater<int>> scoreBoard; // score(desc) -> playerIds
public:
    void addScore(int playerId, int score) {
        int oldScore = playerScores[playerId];
        int newScore = oldScore + score;
        if (oldScore > 0) {
            scoreBoard[oldScore].erase(playerId);
            if (scoreBoard[oldScore].empty()) scoreBoard.erase(oldScore);
        }
        playerScores[playerId] = newScore;
        scoreBoard[newScore].insert(playerId);
    }

    int top(int K) {
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
        int score = playerScores[playerId];
        if (score > 0) {
            scoreBoard[score].erase(playerId);
            if (scoreBoard[score].empty()) scoreBoard.erase(score);
        }
        playerScores[playerId] = 0;
    }

    int getPlayerRank(int playerId) {
        int playerScore = playerScores[playerId];
        int rank = 1;
        for (auto& [score, players] : scoreBoard) {
            if (score <= playerScore) break;
            rank += players.size();
        }
        return rank;
    }
};
