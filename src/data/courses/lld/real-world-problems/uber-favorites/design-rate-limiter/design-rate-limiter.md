# Design a Rate Limiter (Token Bucket, Sliding Window)

Design a rate limiter that controls the rate of requests per client, supporting multiple algorithms.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **allowRequest(clientId)** — return true if request is allowed, false if rate-limited
2. **Per-client limiting** — each client has its own rate limit counter
3. **Multiple algorithms** — Token Bucket, Sliding Window Counter, Fixed Window Counter
4. **Configurable limits** — N requests per M seconds (e.g., 100 req/min)
5. **Thread-safe** — concurrent requests from same client

### Extended Requirements (If Time Permits)

1. Different rate limits per API endpoint
2. Distributed rate limiting (across multiple servers using Redis)
3. Rate limit headers in response (X-RateLimit-Remaining, X-RateLimit-Reset)
4. Whitelist/blacklist (VIP clients, banned clients)
5. Graceful degradation (allow slight burst over limit)
6. Rate limit by IP address, API key, or user ID

<br>

---

## Constraints

- Default limit: 100 requests per minute
- Burst capacity (Token Bucket): 2x sustained rate
- Client count: up to 100,000 concurrent clients
- Memory per client: O(1) for Token Bucket, O(W) for Sliding Window
- Decision latency: < 1ms
- Stale client cleanup: remove clients inactive for > 1 hour

<br>

---

## Identify Primary Actors

1. **API Client** — sends requests that may be rate-limited
   - Actions: make API call, receive 200 (allowed) or 429 (rate limited)

2. **Rate Limiter** — intercepts and evaluates each request
   - Actions: check limit, allow/deny, update counters

3. **Admin** — configures rate limit rules
   - Actions: set limits per endpoint, whitelist/blacklist, view metrics

<br>

---

## Core Entities

### 1. RateLimiter (Interface — Strategy Pattern)
- **Method**: allowRequest(String clientId): boolean
- **Implementations**: TokenBucketLimiter, SlidingWindowLimiter, FixedWindowLimiter

### 2. TokenBucketLimiter
- **State per client**: tokens (double), lastRefillTime
- **Algorithm**: Refill tokens at constant rate; each request consumes 1 token; deny if 0 tokens
- **Allows bursts** up to bucket capacity

### 3. SlidingWindowLimiter
- **State per client**: Deque<Long> of request timestamps
- **Algorithm**: Remove expired timestamps, count remaining; deny if count >= limit
- **Most accurate** but more memory

### 4. FixedWindowLimiter
- **State per client**: windowStart, count
- **Algorithm**: Count requests in current window; deny if count >= limit; reset on window boundary
- **Simplest** but boundary problem (double traffic at window edge)

### 5. RateLimiterFactory
- **Method**: create(String type, int limit, long windowMs): RateLimiter
- **Responsibilities**: Create appropriate limiter based on configuration

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| RateLimiterFactory | creates | RateLimiter | Factory |
| TokenBucketLimiter | implements | RateLimiter | Implementation |
| SlidingWindowLimiter | implements | RateLimiter | Implementation |
| FixedWindowLimiter | implements | RateLimiter | Implementation |
| RateLimiter | tracks | client state (Map) | Composition (◆) |

<br>

---

## Relationships Diagram (Textual UML)

```
  <<interface>> RateLimiter
  +allowRequest(clientId): boolean
       △
  ┌────┼──────────────┬──────────────┐
TokenBucket     SlidingWindow    FixedWindow
-buckets: Map   -logs: Map       -windows: Map
-maxTokens      -maxRequests     -maxRequests
-refillRate     -windowMs        -windowMs

  Client State (per client):
  TokenBucket:    { tokens: 8.5, lastRefill: 1623456789 }
  SlidingWindow:  { timestamps: [t1, t2, t3, ...] }
  FixedWindow:    { windowStart: 1623456780, count: 42 }


  RateLimiterFactory
  +create(type, limit, windowMs): RateLimiter
```

<br>

---

## Design Patterns Used

### 1. **Strategy Pattern**
- **Where**: RateLimiter interface with three concrete algorithm implementations
- **Why**: Different algorithms have different trade-offs (accuracy vs memory vs burst handling)
- **Benefit**: Swap algorithms without changing middleware/gateway code

### 2. **Factory Pattern**
- **Where**: RateLimiterFactory creates appropriate limiter from config
- **Why**: Type is determined at startup from configuration, not hardcoded
- **Benefit**: New algorithms added by implementing interface + adding factory case

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Per-client locking**: `synchronized` per client bucket, not global lock
- **ConcurrentHashMap**: Thread-safe client → state mapping
- **Token refill**: Calculate elapsed time × refill rate — no background thread needed (lazy refill)

### Race Conditions Handled
- **Two requests from same client simultaneously**: `synchronized(clientBucket)` ensures atomic check-and-update
- **Token refill + consume**: Under same lock — refill then consume atomically
- **Client map cleanup**: Background thread periodically removes stale clients; uses `computeIfPresent`

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **First request from new client** — initialize bucket with full tokens / empty window
2. **Exactly at limit** — last allowed request; next one denied
3. **Burst followed by silence** — Token Bucket refills during silence; allows next burst
4. **Fixed window boundary** — client sends 100 requests at 0:59, then 100 at 1:00 → 200 in 2 seconds
5. **Clock skew (distributed)** — use logical timestamps or NTP synchronization
6. **Client sends 0 requests for hours** — cleanup stale entry to save memory
7. **Negative window/limit** — reject in configuration validation
8. **Extremely high refill rate** — cap at maxTokens to prevent overflow

### Error Handling Strategy
- **RateLimitExceededException**: Return HTTP 429 with Retry-After header
- **InvalidConfigException**: Reject invalid limit/window configuration at startup
- **ClientNotFoundException**: Auto-create on first request (lazy initialization)

<br>

---

## Algorithm Comparison

| Algorithm | Accuracy | Memory | Burst | Boundary Problem |
|-----------|----------|--------|-------|-----------------|
| **Token Bucket** | Good | O(1)/client | ✅ Allows burst | No |
| **Sliding Window** | Best | O(N)/client | ❌ Smooth | No |
| **Fixed Window** | Lowest | O(1)/client | ❌ Smooth | ⚠️ Yes (double at edge) |

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including Token Bucket (with lazy refill), Sliding Window (with Deque), Fixed Window, and the Factory for creating limiter instances.
