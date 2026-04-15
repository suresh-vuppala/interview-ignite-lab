#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
#include <mutex>
#include <chrono>
#include <memory>
using namespace std;

class RateLimiter {
public:
    virtual ~RateLimiter() = default;
    virtual bool allowRequest(const string& clientId) = 0;
};

// ========== Token Bucket ==========
class TokenBucketLimiter : public RateLimiter {
    struct Bucket { double tokens; double lastRefillTime; };
    int maxTokens;
    double refillRate;
    unordered_map<string, Bucket> buckets;
    mutex mtx;
    
    double now() {
        return chrono::duration<double>(chrono::steady_clock::now().time_since_epoch()).count();
    }
public:
    TokenBucketLimiter(int maxTokens, double refillRate)
        : maxTokens(maxTokens), refillRate(refillRate) {}
    
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        double t = now();
        auto& bucket = buckets[clientId];
        if (bucket.lastRefillTime == 0) { bucket.tokens = maxTokens; bucket.lastRefillTime = t; }
        
        double elapsed = t - bucket.lastRefillTime;
        bucket.tokens = min((double)maxTokens, bucket.tokens + elapsed * refillRate);
        bucket.lastRefillTime = t;
        
        if (bucket.tokens >= 1) { bucket.tokens--; return true; }
        return false;
    }
};

// ========== Sliding Window ==========
class SlidingWindowLimiter : public RateLimiter {
    int maxRequests;
    long windowMs;
    unordered_map<string, deque<long>> requestLog;
    mutex mtx;
    
    long nowMs() {
        return chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now().time_since_epoch()).count();
    }
public:
    SlidingWindowLimiter(int maxReqs, long windowMs)
        : maxRequests(maxReqs), windowMs(windowMs) {}
    
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        long t = nowMs();
        auto& timestamps = requestLog[clientId];
        while (!timestamps.empty() && t - timestamps.front() > windowMs)
            timestamps.pop_front();
        if ((int)timestamps.size() < maxRequests) { timestamps.push_back(t); return true; }
        return false;
    }
};

// ========== Fixed Window ==========
class FixedWindowLimiter : public RateLimiter {
    struct Window { long start; int count; };
    int maxRequests;
    long windowMs;
    unordered_map<string, Window> windows;
    mutex mtx;
    
    long nowMs() {
        return chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now().time_since_epoch()).count();
    }
public:
    FixedWindowLimiter(int maxReqs, long windowMs)
        : maxRequests(maxReqs), windowMs(windowMs) {}
    
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        long t = nowMs();
        auto& w = windows[clientId];
        if (w.start == 0 || t - w.start > windowMs) { w.start = t; w.count = 0; }
        if (w.count < maxRequests) { w.count++; return true; }
        return false;
    }
};

// Factory
class RateLimiterFactory {
public:
    static unique_ptr<RateLimiter> create(const string& type, int limit, long windowMs) {
        if (type == "token_bucket") return make_unique<TokenBucketLimiter>(limit, (double)limit / (windowMs / 1000));
        if (type == "sliding_window") return make_unique<SlidingWindowLimiter>(limit, windowMs);
        if (type == "fixed_window") return make_unique<FixedWindowLimiter>(limit, windowMs);
        throw invalid_argument("Unknown type: " + type);
    }
};
