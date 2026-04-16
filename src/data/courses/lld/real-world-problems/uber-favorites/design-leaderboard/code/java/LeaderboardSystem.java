// DESIGN: Leaderboard — LLD (Java) | Dual-map: HashMap + TreeMap
import java.util.*;
class Leaderboard {
    Map<Integer,Integer> scores = new HashMap<>();
    TreeMap<Integer,Set<Integer>> board = new TreeMap<>(Collections.reverseOrder());

    void addScore(int pid, int score) {
        int old = scores.getOrDefault(pid, 0), nw = old + score;
        if (old>0) { board.get(old).remove(pid); if(board.get(old).isEmpty()) board.remove(old); }
        scores.put(pid, nw);
        board.computeIfAbsent(nw, k->new HashSet<>()).add(pid);
        System.out.println("  Player"+pid+": +"+score+" = "+nw);
    }

    int top(int K) {
        int total=0, count=0;
        for(var e:board.entrySet()) { int take=Math.min(e.getValue().size(),K-count); total+=e.getKey()*take; count+=take; if(count>=K) break; }
        return total;
    }

    void reset(int pid) {
        int s=scores.getOrDefault(pid,0); if(s>0){board.get(s).remove(pid);if(board.get(s).isEmpty())board.remove(s);}
        scores.put(pid,0); System.out.println("  Reset player"+pid);
    }

    int getRank(int pid) {
        int ps=scores.getOrDefault(pid,0); int rank=1;
        for(var e:board.entrySet()) { if(e.getKey()<=ps) break; rank+=e.getValue().size(); }
        return rank;
    }
}
public class LeaderboardSystem {
    public static void main(String[] args) {
        System.out.println("=== Leaderboard — Java ===");
        Leaderboard lb=new Leaderboard();
        lb.addScore(1,50); lb.addScore(2,80); lb.addScore(3,50); lb.addScore(4,120);
        System.out.println("Top2: "+lb.top(2)); System.out.println("Rank(1): "+lb.getRank(1));
        lb.addScore(1,100); System.out.println("Top2 after: "+lb.top(2));
        lb.reset(4); System.out.println("Top3 after reset: "+lb.top(3));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: HashMap(O(1) lookup) + TreeMap(sorted desc) = O(logN) add, O(K) top
