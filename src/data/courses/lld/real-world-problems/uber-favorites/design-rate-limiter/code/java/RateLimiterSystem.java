// Rate Limiter — Token Bucket + Sliding Window
import java.util.*;
import java.util.concurrent.*;

interface RateLimiter {
    boolean allowRequest(String clientId);
}

// Token Bucket Algorithm
class TokenBucketLimiter implements RateLimiter {
    private final int maxTokens;
    private final double refillRate; // Tokens per second
    private final Map<String, double[]> buckets = new ConcurrentHashMap<>(); // [tokens, lastRefillTime]
    
    public TokenBucketLimiter(int maxTokens, double refillRate) {
        this.maxTokens = maxTokens; this.refillRate = refillRate;
    }
    
    public synchronized boolean allowRequest(String clientId) {
        double now = System.currentTimeMillis() / 1000.0;
        double[] bucket = buckets.computeIfAbsent(clientId, k -> new double[]{maxTokens, now});
        
        // Refill tokens
        double elapsed = now - bucket[1];
        bucket[0] = Math.min(maxTokens, bucket[0] + elapsed * refillRate);
        bucket[1] = now;
        
        if (bucket[0] >= 1) { bucket[0]--; return true; }
        return false; // No tokens left
    }
}

// Sliding Window Counter
class SlidingWindowLimiter implements RateLimiter {
    private final int maxRequests;
    private final long windowMs;
    private final Map<String, Deque<Long>> requestLog = new ConcurrentHashMap<>();
    
    public SlidingWindowLimiter(int maxRequests, long windowMs) {
        this.maxRequests = maxRequests; this.windowMs = windowMs;
    }
    
    public synchronized boolean allowRequest(String clientId) {
        long now = System.currentTimeMillis();
        Deque<Long> timestamps = requestLog.computeIfAbsent(clientId, k -> new LinkedList<>());
        
        // Remove expired entries
        while (!timestamps.isEmpty() && now - timestamps.peekFirst() > windowMs)
            timestamps.pollFirst();
        
        if (timestamps.size() < maxRequests) { timestamps.addLast(now); return true; }
        return false;
    }
}

// Fixed Window Counter (simplest)
class FixedWindowLimiter implements RateLimiter {
    private final int maxRequests;
    private final long windowMs;
    private final Map<String, long[]> windows = new ConcurrentHashMap<>(); // [windowStart, count]
    
    public synchronized boolean allowRequest(String clientId) {
        long now = System.currentTimeMillis();
        long[] window = windows.computeIfAbsent(clientId, k -> new long[]{now, 0});
        if (now - window[0] > windowMs) { window[0] = now; window[1] = 0; }
        if (window[1] < maxRequests) { window[1]++; return true; }
        return false;
    }
}

// Factory
class RateLimiterFactory {
    public static RateLimiter create(String type, int limit, long windowMs) {
        return switch (type) {
            case "token_bucket" -> new TokenBucketLimiter(limit, (double) limit / (windowMs / 1000));
            case "sliding_window" -> new SlidingWindowLimiter(limit, windowMs);
            case "fixed_window" -> new FixedWindowLimiter(limit, windowMs);
            default -> throw new IllegalArgumentException("Unknown: " + type);
        };
    }
}
