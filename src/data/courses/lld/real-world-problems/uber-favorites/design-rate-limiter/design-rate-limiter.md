# Design a Rate Limiter

Design a rate limiter that controls the rate of requests per client, supporting multiple algorithms.

<br>

---

## Requirements

### Main Requirements
1. **Allow/deny request** based on rate limit rules
2. **Per-client limiting** — each client has own limit
3. **Multiple algorithms** — Token Bucket, Sliding Window, Fixed Window
4. **Configurable** — requests per second/minute/hour
5. **Thread-safe** — concurrent requests

<br>

---

## Algorithms

### Token Bucket
- Bucket holds tokens (max = burst capacity)
- Tokens added at fixed rate (e.g., 10/sec)
- Each request consumes 1 token
- If no tokens → reject

### Sliding Window Counter
- Count requests in last N seconds
- If count > limit → reject
- More accurate than fixed window

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Strategy** | RateLimiter algorithms | Swap between Token Bucket, Sliding Window |
| **Factory** | Create appropriate limiter per configuration | Decouple creation |

<br>

---

## Interview Tips

- Token Bucket is most commonly asked
- Discuss trade-offs: Token Bucket allows bursts; Sliding Window is smoother
- Per-client state: HashMap<clientId, RateLimiter>
- Distributed rate limiting: Redis + Lua scripts (mention for bonus points)
