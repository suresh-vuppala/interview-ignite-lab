#include <unordered_map>
#include <deque>
#include <chrono>
#include <mutex>
#include <iostream>
using namespace std;

class RateLimiter {
public:
    virtual ~RateLimiter() = default;
    virtual bool allowRequest(const string& clientId) = 0;
};

// ========== TOKEN BUCKET ==========
class TokenBucketLimiter : public RateLimiter {
    struct Bucket { double tokens; double lastRefillTime; };
    int maxTokens;
    double refillRate;
    unordered_map<string, Bucket> buckets;
    mutex mtx;
    double now() { return chrono::duration<double>(chrono::steady_clock::now().time_since_epoch()).count(); }
public:
    TokenBucketLimiter(int maxTokens, double refillRate) : maxTokens(maxTokens), refillRate(refillRate) {}
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        double t = now();
        auto& b = buckets[clientId];
        if (b.tokens == 0 && b.lastRefillTime == 0) { b.tokens = maxTokens; b.lastRefillTime = t; }
        double elapsed = t - b.lastRefillTime;
        b.tokens = min((double)maxTokens, b.tokens + elapsed * refillRate);
        b.lastRefillTime = t;
        if (b.tokens >= 1) { b.tokens--; return true; }
        return false;
    }
};

// ========== SLIDING WINDOW ==========
class SlidingWindowLimiter : public RateLimiter {
    int maxRequests;
    long windowMs;
    unordered_map<string, deque<long>> requestLog;
    mutex mtx;
    long nowMs() { return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); }
public:
    SlidingWindowLimiter(int maxReqs, long windowMs) : maxRequests(maxReqs), windowMs(windowMs) {}
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        long t = nowMs();
        auto& timestamps = requestLog[clientId];
        while (!timestamps.empty() && t - timestamps.front() > windowMs) timestamps.pop_front();
        if ((int)timestamps.size() < maxRequests) { timestamps.push_back(t); return true; }
        return false;
    }
};

// ========== FIXED WINDOW ==========
class FixedWindowLimiter : public RateLimiter {
    struct Window { long start; int count; };
    int maxRequests;
    long windowMs;
    unordered_map<string, Window> windows;
    mutex mtx;
    long nowMs() { return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); }
public:
    FixedWindowLimiter(int maxReqs, long windowMs) : maxRequests(maxReqs), windowMs(windowMs) {}
    bool allowRequest(const string& clientId) override {
        lock_guard<mutex> lock(mtx);
        long t = nowMs();
        auto& w = windows[clientId];
        if (t - w.start > windowMs) { w.start = t; w.count = 0; }
        if (w.count < maxRequests) { w.count++; return true; }
        return false;
    }
};
