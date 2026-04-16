// ===========================================================================
// DESIGN: Rate Limiter — Low Level Design
// Patterns: Strategy, Factory | Algorithms: Token Bucket, Sliding Window, Fixed Window
// ===========================================================================
// FR: allowRequest(clientId), per-client, multiple algorithms, configurable
// PLANTUML: RateLimiter<|..TokenBucket, RateLimiter<|..SlidingWindow, RateLimiter<|..FixedWindow

#include <iostream>
#include <string>
#include <map>
#include <deque>
using namespace std;

// Strategy interface
class RateLimiter {
public:
    virtual ~RateLimiter() {}
    virtual bool allowRequest(const string& clientId, long timestamp) = 0;
    virtual string describe() const = 0;
};

// Token Bucket: allows bursts up to capacity
class TokenBucketLimiter : public RateLimiter {
    struct Bucket { double tokens; long lastRefill; };
    int maxTokens;
    double refillRate;  // tokens per second
    map<string, Bucket> buckets;
public:
    TokenBucketLimiter(int maxTokens, double refillRate)
        : maxTokens(maxTokens), refillRate(refillRate) {}

    bool allowRequest(const string& clientId, long timestamp) {
        Bucket& b = buckets[clientId];
        if (b.lastRefill == 0) { b.tokens = maxTokens; b.lastRefill = timestamp; }
        // Refill
        long elapsed = timestamp - b.lastRefill;
        b.tokens = min((double)maxTokens, b.tokens + elapsed * refillRate);
        b.lastRefill = timestamp;
        if (b.tokens >= 1) { b.tokens--; return true; }
        return false;
    }
    string describe() const { return "TokenBucket"; }
};

// Sliding Window: exact count in window
class SlidingWindowLimiter : public RateLimiter {
    int maxRequests;
    long windowSec;
    map<string, deque<long> > logs;
public:
    SlidingWindowLimiter(int max, long window) : maxRequests(max), windowSec(window) {}

    bool allowRequest(const string& clientId, long timestamp) {
        deque<long>& q = logs[clientId];
        while (!q.empty() && timestamp - q.front() >= windowSec) q.pop_front();
        if ((int)q.size() < maxRequests) { q.push_back(timestamp); return true; }
        return false;
    }
    string describe() const { return "SlidingWindow"; }
};

// Fixed Window: simple counter reset per window
class FixedWindowLimiter : public RateLimiter {
    struct Window { long start; int count; };
    int maxRequests;
    long windowSec;
    map<string, Window> windows;
public:
    FixedWindowLimiter(int max, long window) : maxRequests(max), windowSec(window) {}

    bool allowRequest(const string& clientId, long timestamp) {
        Window& w = windows[clientId];
        if (w.start == 0 || timestamp - w.start >= windowSec) { w.start = timestamp; w.count = 0; }
        if (w.count < maxRequests) { w.count++; return true; }
        return false;
    }
    string describe() const { return "FixedWindow"; }
};

int main() {
    cout << "============================================\n  Rate Limiter — LLD Demo\n============================================" << endl;

    // Token Bucket: 5 tokens, refill 1/sec
    TokenBucketLimiter tb(5, 1.0);
    cout << "\n--- Token Bucket (5 tokens, 1/sec refill) ---" << endl;
    for (int t = 0; t < 10; t++)
        cout << "  t=" << t << " client1: " << (tb.allowRequest("client1", t) ? "ALLOW" : "DENY") << endl;

    // Sliding Window: 3 per 5 seconds
    SlidingWindowLimiter sw(3, 5);
    cout << "\n--- Sliding Window (3 per 5s) ---" << endl;
    for (int t = 0; t < 10; t++)
        cout << "  t=" << t << " client1: " << (sw.allowRequest("client1", t) ? "ALLOW" : "DENY") << endl;

    // Fixed Window: 3 per 5 seconds
    FixedWindowLimiter fw(3, 5);
    cout << "\n--- Fixed Window (3 per 5s) ---" << endl;
    for (int t = 0; t < 10; t++)
        cout << "  t=" << t << " client1: " << (fw.allowRequest("client1", t) ? "ALLOW" : "DENY") << endl;

    cout << "\n=== Complete ===" << endl;
    return 0;
}
// SUMMARY: Strategy(3 algorithms), Factory(create by config)
// TOKEN BUCKET: allows bursts, lazy refill
// SLIDING WINDOW: most accurate, O(N) memory
// FIXED WINDOW: simplest, boundary problem
