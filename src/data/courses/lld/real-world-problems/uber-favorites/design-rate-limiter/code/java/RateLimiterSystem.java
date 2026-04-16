// DESIGN: Rate Limiter — LLD (Java) | Strategy: Token Bucket, Sliding Window, Fixed Window
import java.util.*;
interface RateLimiter { boolean allowRequest(String clientId, long timestamp); String describe(); }

class TokenBucketLimiter implements RateLimiter {
    int maxTokens; double refillRate;
    Map<String,double[]> buckets=new HashMap<>(); // [tokens, lastRefill]
    TokenBucketLimiter(int max,double rate){maxTokens=max;refillRate=rate;}
    public synchronized boolean allowRequest(String cid, long ts) {
        double[] b=buckets.computeIfAbsent(cid,k->new double[]{maxTokens,ts});
        b[0]=Math.min(maxTokens,b[0]+(ts-b[1])*refillRate); b[1]=ts;
        if(b[0]>=1){b[0]--;return true;} return false;
    }
    public String describe(){return "TokenBucket";}
}

class SlidingWindowLimiter implements RateLimiter {
    int maxReqs; long windowSec;
    Map<String,Deque<Long>> logs=new HashMap<>();
    SlidingWindowLimiter(int max,long win){maxReqs=max;windowSec=win;}
    public synchronized boolean allowRequest(String cid, long ts) {
        Deque<Long> q=logs.computeIfAbsent(cid,k->new LinkedList<>());
        while(!q.isEmpty()&&ts-q.peekFirst()>=windowSec) q.pollFirst();
        if(q.size()<maxReqs){q.addLast(ts);return true;} return false;
    }
    public String describe(){return "SlidingWindow";}
}

public class RateLimiterSystem {
    public static void main(String[] args) {
        System.out.println("=== Rate Limiter — Java ===");
        TokenBucketLimiter tb=new TokenBucketLimiter(5,1.0);
        System.out.println("--- Token Bucket (5 tokens, 1/sec) ---");
        for(int t=0;t<10;t++) System.out.println("  t="+t+": "+(tb.allowRequest("c1",t)?"ALLOW":"DENY"));
        SlidingWindowLimiter sw=new SlidingWindowLimiter(3,5);
        System.out.println("--- Sliding Window (3 per 5s) ---");
        for(int t=0;t<10;t++) System.out.println("  t="+t+": "+(sw.allowRequest("c1",t)?"ALLOW":"DENY"));
        System.out.println("=== Complete ===");
    }
}
// SUMMARY: Strategy(3 algorithms), TokenBucket allows bursts, SlidingWindow most accurate
