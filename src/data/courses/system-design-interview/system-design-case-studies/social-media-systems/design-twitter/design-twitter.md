# Design Twitter/X

## Interview Question
**"Design a Twitter-like social media platform that can handle 500M users posting tweets, following other users, and viewing their timeline."**

---

## Step 1: Requirements Clarification

### Functional Requirements
- **Post tweets** (280 characters max)
- **Follow/unfollow users**
- **View timeline** (home feed)
- **View user profile**
- **Search tweets**
- **Like and retweet**

### Non-Functional Requirements
- **500M total users, 100M DAU**
- **300M tweets per day**
- **Timeline should load in <200ms**
- **99.9% availability**
- **Global distribution**

### Out of Scope
- Direct messaging
- Video/image uploads
- Advanced analytics
- Ads system

---

## Step 2: Capacity Estimation

### User Activity
```
Daily Active Users: 100M
Average tweets per user per day: 3
Total tweets per day: 300M
Tweets per second: 300M / (24 * 3600) = 3,500 TPS
Peak TPS: 3,500 * 5 = 17,500 TPS
```

### Timeline Reads
```
Average timeline views per user: 50/day
Total timeline requests: 100M * 50 = 5B/day
Timeline QPS: 5B / (24 * 3600) = 58K QPS
Peak QPS: 58K * 5 = 290K QPS
```

### Storage Requirements
```
Tweet size: 280 chars * 2 bytes = 560 bytes
Metadata: 200 bytes (user_id, timestamp, etc.)
Total per tweet: 760 bytes ≈ 1KB

Daily storage: 300M tweets * 1KB = 300GB/day
Annual storage: 300GB * 365 = 110TB/year
With replication (3x): 330TB/year
```

### Bandwidth
```
Write bandwidth: 17,500 TPS * 1KB = 17.5 MB/s
Read bandwidth: 290K QPS * 1KB = 290 MB/s
```

---

## Step 3: High-Level Design

```
[Client] → [Load Balancer] → [API Gateway] → [Microservices]
                                                    ↓
[Cache Layer] ← [Application Servers] → [Message Queue]
     ↓                                        ↓
[Database Cluster] ← [Timeline Service] ← [Fanout Service]
```

### Core Components
1. **Load Balancer**: Distribute traffic across servers
2. **API Gateway**: Authentication, rate limiting, routing
3. **Tweet Service**: Handle tweet CRUD operations
4. **Timeline Service**: Generate user timelines
5. **User Service**: Manage user profiles and relationships
6. **Fanout Service**: Distribute tweets to followers
7. **Cache Layer**: Redis for hot data
8. **Database**: Sharded MySQL/PostgreSQL

---

## Step 4: Database Design

### Tweet Table
```sql
CREATE TABLE tweets (
    tweet_id BIGINT PRIMARY KEY,
    user_id BIGINT NOT NULL,
    content VARCHAR(280) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    like_count INT DEFAULT 0,
    retweet_count INT DEFAULT 0,
    INDEX idx_user_created (user_id, created_at),
    INDEX idx_created (created_at)
);
```

### User Table
```sql
CREATE TABLE users (
    user_id BIGINT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    created_at TIMESTAMP NOT NULL,
    follower_count INT DEFAULT 0,
    following_count INT DEFAULT 0
);
```

### Followers Table
```sql
CREATE TABLE followers (
    follower_id BIGINT NOT NULL,
    followee_id BIGINT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    PRIMARY KEY (follower_id, followee_id),
    INDEX idx_followee (followee_id)
);
```

### Timeline Cache (Redis)
```
Key: timeline:{user_id}
Value: [tweet_id1, tweet_id2, tweet_id3, ...]
TTL: 1 hour
```

---

## Step 5: Detailed Design

### Timeline Generation Strategies

#### Push Model (Fanout on Write)
```python
def post_tweet(user_id, content):
    # 1. Save tweet to database
    tweet_id = save_tweet(user_id, content)
    
    # 2. Get all followers
    followers = get_followers(user_id)
    
    # 3. Push to each follower's timeline
    for follower_id in followers:
        add_to_timeline_cache(follower_id, tweet_id)
    
    return tweet_id
```

**Pros**: Fast timeline reads
**Cons**: Slow writes for users with many followers

#### Pull Model (Fanout on Read)
```python
def get_timeline(user_id):
    # 1. Get users that this user follows
    following = get_following(user_id)
    
    # 2. Get recent tweets from each
    tweets = []
    for followee_id in following:
        recent_tweets = get_recent_tweets(followee_id)
        tweets.extend(recent_tweets)
    
    # 3. Sort by timestamp and return top N
    return sort_by_timestamp(tweets)[:100]
```

**Pros**: Fast writes
**Cons**: Slow timeline reads

#### Hybrid Approach
```python
def post_tweet(user_id, content):
    tweet_id = save_tweet(user_id, content)
    
    if is_celebrity(user_id):
        # Pull model for celebrities
        return tweet_id
    else:
        # Push model for regular users
        fanout_to_followers(user_id, tweet_id)
        return tweet_id

def get_timeline(user_id):
    # Get pre-computed timeline
    timeline = get_timeline_cache(user_id)
    
    # Merge with celebrity tweets (pull)
    celebrity_tweets = get_celebrity_tweets(user_id)
    
    return merge_and_sort(timeline, celebrity_tweets)
```

### API Design

#### Post Tweet
```
POST /api/v1/tweets
{
    "content": "Hello World!",
    "media_urls": []
}

Response:
{
    "tweet_id": "123456789",
    "created_at": "2024-01-01T12:00:00Z"
}
```

#### Get Timeline
```
GET /api/v1/timeline?limit=20&cursor=abc123

Response:
{
    "tweets": [...],
    "next_cursor": "def456",
    "has_more": true
}
```

#### Follow User
```
POST /api/v1/users/{user_id}/follow

Response:
{
    "success": true,
    "following_count": 150
}
```

---

## Step 6: Scaling the Design

### Database Sharding

#### Tweet Sharding by Tweet ID
```
Shard = tweet_id % num_shards
```
**Pros**: Even distribution
**Cons**: Can't efficiently query user's tweets

#### Tweet Sharding by User ID
```
Shard = user_id % num_shards
```
**Pros**: User tweets on same shard
**Cons**: Hot users create hot shards

#### Hybrid Sharding
- Shard tweets by user_id for write efficiency
- Maintain global secondary index for timeline queries
- Use consistent hashing for better distribution

### Caching Strategy

#### Multi-Level Caching
```
L1: Application Cache (in-memory)
L2: Redis Cluster (distributed)
L3: CDN (for static content)
```

#### Cache Keys
```
timeline:{user_id} → List of tweet IDs
tweet:{tweet_id} → Tweet content and metadata
user:{user_id} → User profile data
trending:{region} → Trending topics
```

### Performance Optimizations

#### Timeline Pre-computation
- Pre-compute timelines for active users
- Use background jobs to update timelines
- Store multiple timeline versions (last hour, day, week)

#### Hot Data Identification
```python
# Identify trending tweets
if tweet.engagement_rate > threshold:
    cache_in_multiple_regions(tweet)
    increase_cache_ttl(tweet)
```

#### Read Replicas
- Use read replicas for timeline queries
- Route reads to nearest geographic replica
- Implement eventual consistency for non-critical reads

---

## Step 7: Monitoring and Reliability

### Key Metrics
- **Tweet posting rate** (TPS)
- **Timeline load time** (P95, P99)
- **Cache hit ratio** (>95%)
- **Database query time** (P95 < 100ms)
- **Error rates** (<0.1%)

### Failure Handling

#### Database Failures
```python
def get_timeline_with_fallback(user_id):
    try:
        return get_timeline_from_primary(user_id)
    except DatabaseError:
        return get_timeline_from_replica(user_id)
    except Exception:
        return get_cached_timeline(user_id)
```

#### Cache Failures
- Implement circuit breakers
- Graceful degradation to database
- Cache warming strategies

#### Service Failures
- Microservice isolation
- Bulkhead pattern
- Timeout and retry policies

### Disaster Recovery
- Multi-region deployment
- Cross-region data replication
- Automated failover procedures
- Regular disaster recovery drills

---

## Alternative Approaches

### Event-Driven Architecture
```
Tweet Posted → Event Bus → [Timeline Service, Search Service, Analytics Service]
```

### CQRS (Command Query Responsibility Segregation)
- Separate write and read models
- Optimized read databases for timeline queries
- Event sourcing for audit trails

### GraphQL API
- Single endpoint for flexible queries
- Reduce over-fetching
- Real-time subscriptions for live updates

---

## Trade-offs Discussion

### Consistency vs Availability
- **Strong consistency**: Immediate timeline updates, slower performance
- **Eventual consistency**: Faster performance, delayed timeline updates
- **Chosen**: Eventual consistency with <1 second delay

### Storage vs Compute
- **Pre-compute timelines**: More storage, faster reads
- **Compute on-demand**: Less storage, slower reads
- **Chosen**: Hybrid approach based on user activity

### Cost vs Performance
- **High-end hardware**: Better performance, higher cost
- **Commodity hardware**: Lower cost, more complexity
- **Chosen**: Commodity hardware with smart caching

---

## Follow-up Questions

### How would you handle viral tweets?
- Implement trending detection algorithms
- Auto-scale cache clusters for hot content
- Use CDN for viral content distribution
- Rate limiting to prevent system overload

### How would you implement real-time notifications?
- WebSocket connections for active users
- Push notifications for mobile users
- Message queues for reliable delivery
- Batching for efficiency

### How would you handle spam and abuse?
- Content filtering algorithms
- Rate limiting per user
- Machine learning for spam detection
- User reporting and moderation tools

### How would you implement search?
- Elasticsearch for full-text search
- Real-time indexing pipeline
- Autocomplete with Trie data structure
- Trending topics calculation

---

## Summary

This Twitter design handles:
- **500M users** with horizontal scaling
- **300M tweets/day** with efficient storage
- **290K QPS** timeline reads with caching
- **Global distribution** with CDN and replicas
- **High availability** with redundancy and failover

Key design decisions:
1. **Hybrid fanout** for timeline generation
2. **Sharded databases** for horizontal scaling
3. **Multi-level caching** for performance
4. **Microservices** for maintainability
5. **Event-driven** architecture for scalability