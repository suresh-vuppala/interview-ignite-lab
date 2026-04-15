// Leaderboard — HashMap + TreeMap
import java.util.*;

class Leaderboard {
    private Map<Integer, Integer> playerScores; // playerId → total score
    private TreeMap<Integer, Set<Integer>> scoreBoard; // score → set of playerIds (descending)
    
    public Leaderboard() {
        playerScores = new HashMap<>();
        scoreBoard = new TreeMap<>(Collections.reverseOrder()); // Descending
    }
    
    public void addScore(int playerId, int score) {
        int oldScore = playerScores.getOrDefault(playerId, 0);
        int newScore = oldScore + score;
        
        // Remove from old position
        if (oldScore > 0) {
            Set<Integer> players = scoreBoard.get(oldScore);
            players.remove(playerId);
            if (players.isEmpty()) scoreBoard.remove(oldScore);
        }
        
        // Add to new position
        playerScores.put(playerId, newScore);
        scoreBoard.computeIfAbsent(newScore, k -> new HashSet<>()).add(playerId);
    }
    
    public int top(int K) {
        int total = 0, count = 0;
        for (Map.Entry<Integer, Set<Integer>> entry : scoreBoard.entrySet()) {
            int score = entry.getKey();
            int playersAtScore = entry.getValue().size();
            int take = Math.min(playersAtScore, K - count);
            total += score * take;
            count += take;
            if (count >= K) break;
        }
        return total;
    }
    
    public void reset(int playerId) {
        int score = playerScores.getOrDefault(playerId, 0);
        if (score > 0) {
            Set<Integer> players = scoreBoard.get(score);
            players.remove(playerId);
            if (players.isEmpty()) scoreBoard.remove(score);
        }
        playerScores.put(playerId, 0);
    }
    
    public int getPlayerRank(int playerId) {
        int playerScore = playerScores.getOrDefault(playerId, 0);
        int rank = 1;
        for (Map.Entry<Integer, Set<Integer>> entry : scoreBoard.entrySet()) {
            if (entry.getKey() <= playerScore) break;
            rank += entry.getValue().size();
        }
        return rank;
    }
}
