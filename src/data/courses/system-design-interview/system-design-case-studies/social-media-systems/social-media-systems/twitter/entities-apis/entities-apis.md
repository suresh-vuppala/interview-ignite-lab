# Twitter System Design: Entities & API Design

## Interview Conversation

**Interviewer**: "Now let's design our data model and APIs. What entities do you think we need for our Twitter system?"

**Candidate**: "Great! Let me approach this systematically. I'll start by identifying the core entities based on our functional requirements, then design the database schema, and finally create the API contracts.

From our requirements, I can identify these core entities:
1. **User** - represents people using the platform
2. **Tweet** - the content users post
3. **Follow** - the social graph relationships
4. **Timeline** - potentially a derived entity for performance

Let me design each one in detail, thinking about both the logical model and the physical storage considerations."

---

## Entity Design Deep Dive

### 1. User Entity

**Candidate's Analysis**:
"The User entity is foundational to everything else. Let me think through all the attributes we need:

#### User Schema Design
```sql
CREATE TABLE users (
    user_id BIGINT PRIMARY KEY,           -- Unique identifier
    username VARCHAR(50) UNIQUE NOT NULL, -- @handle (unique, indexed)
    email VARCHAR(255) UNIQUE NOT NULL,   -- For authentication
    display_name VARCHAR(100),            -- Full name shown on profile
    bio TEXT,                            -- Profile description
    profile_image_url VARCHAR(500),       -- Profile picture
    created_at TIMESTAMP NOT NULL,       -- Account creation time
    updated_at TIMESTAMP NOT NULL,       -- Last profile update
    
    -- Denormalized counters for performance
    follower_count INT DEFAULT 0,        -- Number of followers
    following_count INT DEFAULT 0,       -- Number of people they follow
    tweet_count INT DEFAULT 0,           -- Total tweets posted
    
    -- Account status
    is_verified BOOLEAN DEFAULT FALSE,   -- Blue checkmark
    is_active BOOLEAN DEFAULT TRUE,      -- Account status
    
    -- Indexes
    INDEX idx_username (username),
    INDEX idx_email (email),
    INDEX idx_created_at (created_at)
);
```

#### Design Decisions Explained

**Candidate**: "Let me explain my key design choices:

1. **BIGINT for user_id**: We expect 500M+ users, so we need a large ID space
2. **Denormalized counters**: Follower/following counts are displayed frequently, so we cache them here rather than counting in real-time
3. **Username constraints**: 50 characters max, unique, indexed for fast lookups
4. **Timestamps**: Both created_at and updated_at for audit trails

**Trade-offs:**
- **Pro**: Fast profile loading, no need to count relationships
- **Con**: Need to maintain counter consistency when follows change
- **Decision**: Accept eventual consistency for counters to optimize for read performance"

**Interviewer**: "Good thinking on the denormalized counters. How do you plan to keep them consistent?"

**Candidate**: "I'd use an event-driven approach - when a follow/unfollow happens, we publish an event that updates the counters asynchronously. This keeps the follow operation fast while ensuring counters are eventually consistent."

### 2. Tweet Entity

**Candidate's Design Process**:
"Tweets are the core content. Let me design this carefully:

#### Tweet Schema Design
```sql
CREATE TABLE tweets (
    tweet_id BIGINT PRIMARY KEY,         -- Unique tweet identifier
    user_id BIGINT NOT NULL,             -- Author of the tweet
    content TEXT NOT NULL,               -- Tweet text (max 280 chars)
    created_at TIMESTAMP NOT NULL,       -- When tweet was posted
    
    -- Engagement metrics (denormalized)
    like_count INT DEFAULT 0,            -- Number of likes
    retweet_count INT DEFAULT 0,         -- Number of retweets
    reply_count INT DEFAULT 0,           -- Number of replies
    
    -- Tweet metadata
    reply_to_tweet_id BIGINT,            -- If this is a reply
    original_tweet_id BIGINT,            -- If this is a retweet
    
    -- Indexes for efficient queries
    INDEX idx_user_created (user_id, created_at DESC), -- User's tweets
    INDEX idx_created_at (created_at DESC),            -- Global timeline
    
    FOREIGN KEY (user_id) REFERENCES users(user_id),
    FOREIGN KEY (reply_to_tweet_id) REFERENCES tweets(tweet_id),
    FOREIGN KEY (original_tweet_id) REFERENCES tweets(tweet_id)
);
```

#### Tweet ID Generation Strategy

**Candidate**: "For tweet_id, I need a strategy that works at scale:

**Option 1: Auto-increment**
- **Pros**: Simple, sequential
- **Cons**: Single point of contention, reveals tweet volume

**Option 2: UUID**
- **Pros**: Distributed generation, no collisions
- **Cons**: 128-bit overhead, not time-sortable

**Option 3: Snowflake ID (Twitter's approach)**
- **Pros**: 64-bit, time-sortable, distributed generation
- **Cons**: Slightly more complex implementation

**My choice**: Snowflake ID because it's time-sortable (helps with timeline ordering) and can be generated in a distributed manner."

**Interviewer**: "Snowflake ID is a good choice. Can you explain how it works?"

**Candidate**: "Sure! Snowflake ID is a 64-bit integer with this structure:
- 1 bit: Sign bit (always 0)
- 41 bits: Timestamp (milliseconds since epoch)
- 10 bits: Machine ID (supports 1024 machines)
- 12 bits: Sequence number (4096 IDs per millisecond per machine)

This gives us time-ordered IDs that can be generated independently on each server."

### 3. Follow Relationship Entity

**Candidate's Social Graph Design**:
"The follow relationship is crucial for timeline generation:

#### Follow Schema Design
```sql
CREATE TABLE follows (
    follower_id BIGINT NOT NULL,         -- User who is following
    followee_id BIGINT NOT NULL,         -- User being followed
    created_at TIMESTAMP NOT NULL,      -- When the follow happened
    
    PRIMARY KEY (follower_id, followee_id),
    INDEX idx_follower (follower_id),    -- Get who user follows
    INDEX idx_followee (followee_id),    -- Get user's followers
    INDEX idx_created_at (created_at),   -- Recent follows
    
    FOREIGN KEY (follower_id) REFERENCES users(user_id),
    FOREIGN KEY (followee_id) REFERENCES users(user_id)
);
```

#### Social Graph Query Patterns

**Candidate**: "This table needs to support several query patterns efficiently:

1. **Get followers**: `SELECT follower_id FROM follows WHERE followee_id = ?`
2. **Get following**: `SELECT followee_id FROM follows WHERE follower_id = ?`
3. **Check relationship**: `SELECT 1 FROM follows WHERE follower_id = ? AND followee_id = ?`

The composite primary key and indexes support all these patterns efficiently."

### 4. Timeline Entity (Optional)

**Candidate's Performance Optimization**:
"For timeline performance, I'm considering a materialized timeline table:

#### Timeline Cache Schema
```sql
CREATE TABLE user_timelines (
    user_id BIGINT NOT NULL,             -- Timeline owner
    tweet_id BIGINT NOT NULL,            -- Tweet in timeline
    created_at TIMESTAMP NOT NULL,       -- Tweet creation time
    inserted_at TIMESTAMP NOT NULL,     -- When added to timeline
    
    PRIMARY KEY (user_id, created_at DESC, tweet_id),
    INDEX idx_user_created (user_id, created_at DESC),
    
    FOREIGN KEY (user_id) REFERENCES users(user_id),
    FOREIGN KEY (tweet_id) REFERENCES tweets(tweet_id)
);
```

**Trade-off Analysis:**
- **Pro**: Extremely fast timeline reads (just a range query)
- **Con**: Significant storage overhead, complex to maintain
- **Decision**: I'll design the system to work without this initially, but keep it as an optimization option"

**Interviewer**: "Smart to keep that as an option. Now let's talk about the APIs."

---

## API Design

**Candidate**: "Let me design RESTful APIs that support our functional requirements efficiently:

### 1. User Management APIs

#### User Registration
```http
POST /api/v1/users
Content-Type: application/json

{
    "username": "john_doe",
    "email": "john@example.com",
    "display_name": "John Doe",
    "password": "hashed_password"
}

Response (201 Created):
{
    "user_id": "123456789012345678",
    "username": "john_doe",
    "display_name": "John Doe",
    "created_at": "2024-01-15T10:30:00Z"
}
```

#### Get User Profile
```http
GET /api/v1/users/{user_id}

Response (200 OK):
{
    "user_id": "123456789012345678",
    "username": "john_doe",
    "display_name": "John Doe",
    "bio": "Software engineer at Google",
    "profile_image_url": "https://cdn.twitter.com/profiles/123.jpg",
    "follower_count": 1250,
    "following_count": 890,
    "tweet_count": 2340,
    "created_at": "2024-01-15T10:30:00Z",
    "is_verified": false
}
```

### 2. Tweet Management APIs

#### Post Tweet
```http
POST /api/v1/tweets
Authorization: Bearer {jwt_token}
Content-Type: application/json

{
    "content": "Just shipped a new feature! 🚀",
    "reply_to_tweet_id": null  // Optional, for replies
}

Response (201 Created):
{
    "tweet_id": "987654321098765432",
    "user_id": "123456789012345678",
    "content": "Just shipped a new feature! 🚀",
    "created_at": "2024-01-15T14:30:00Z",
    "like_count": 0,
    "retweet_count": 0,
    "reply_count": 0
}
```

#### Get Tweet
```http
GET /api/v1/tweets/{tweet_id}

Response (200 OK):
{
    "tweet_id": "987654321098765432",
    "user": {
        "user_id": "123456789012345678",
        "username": "john_doe",
        "display_name": "John Doe",
        "profile_image_url": "https://cdn.twitter.com/profiles/123.jpg"
    },
    "content": "Just shipped a new feature! 🚀",
    "created_at": "2024-01-15T14:30:00Z",
    "like_count": 42,
    "retweet_count": 15,
    "reply_count": 8
}
```

#### Get User's Tweets
```http
GET /api/v1/users/{user_id}/tweets?limit=20&cursor=abc123

Response (200 OK):
{
    "tweets": [...],  // Array of tweet objects
    "next_cursor": "def456",
    "has_more": true
}
```

### 3. Social Graph APIs

#### Follow User
```http
POST /api/v1/users/{user_id}/follow
Authorization: Bearer {jwt_token}

Response (200 OK):
{
    "success": true,
    "following": true,
    "follower_count": 1251  // Updated count
}
```

#### Unfollow User
```http
DELETE /api/v1/users/{user_id}/follow
Authorization: Bearer {jwt_token}

Response (200 OK):
{
    "success": true,
    "following": false,
    "follower_count": 1250  // Updated count
}
```

#### Get Followers
```http
GET /api/v1/users/{user_id}/followers?limit=50&cursor=xyz789

Response (200 OK):
{
    "users": [...],  // Array of user objects
    "next_cursor": "abc123",
    "has_more": true
}
```

### 4. Timeline APIs

#### Get Home Timeline
```http
GET /api/v1/timeline/home?limit=20&cursor=timeline_cursor_123
Authorization: Bearer {jwt_token}

Response (200 OK):
{
    "tweets": [
        {
            "tweet_id": "987654321098765432",
            "user": {
                "user_id": "123456789012345678",
                "username": "john_doe",
                "display_name": "John Doe",
                "profile_image_url": "https://cdn.twitter.com/profiles/123.jpg"
            },
            "content": "Just shipped a new feature! 🚀",
            "created_at": "2024-01-15T14:30:00Z",
            "like_count": 42,
            "retweet_count": 15,
            "reply_count": 8
        }
        // ... more tweets
    ],
    "next_cursor": "timeline_cursor_456",
    "has_more": true
}
```

**Interviewer**: "I like the cursor-based pagination. Can you explain why you chose that over offset-based pagination?"

**Candidate**: "Great question! Cursor-based pagination is better for real-time feeds because:

1. **Consistency**: New tweets don't shift the results, avoiding duplicates
2. **Performance**: No need to skip records like with OFFSET
3. **Real-time friendly**: Cursors can encode timestamp information

For timeline cursors, I'd encode the timestamp of the last tweet, so the next page starts from that point."

---

## API Design Principles

**Candidate's Design Philosophy**:

### 1. RESTful Design
- **Resource-based URLs**: `/users/{id}`, `/tweets/{id}`
- **HTTP methods**: GET for reads, POST for creates, DELETE for removes
- **Status codes**: Proper HTTP status codes for different scenarios

### 2. Pagination Strategy
- **Cursor-based**: Better for real-time data
- **Consistent format**: All paginated endpoints use same structure
- **Metadata**: Include `has_more` and `next_cursor` for client convenience

### 3. Response Format Consistency
```json
{
    "data": {...},           // Main response data
    "meta": {                // Metadata about the response
        "timestamp": "...",
        "request_id": "..."
    },
    "errors": [...]          // Error details if any
}
```

### 4. Authentication & Authorization
- **JWT tokens**: Stateless authentication
- **Bearer token**: Standard Authorization header
- **Scope-based**: Different permissions for different operations

### 5. Rate Limiting Headers
```http
X-RateLimit-Limit: 1000
X-RateLimit-Remaining: 999
X-RateLimit-Reset: 1642694400
```

**Interviewer**: "Excellent API design. I particularly like the consistency across endpoints. How would you handle API versioning?"

**Candidate**: "I'd use URL versioning (`/api/v1/`) because it's explicit and allows us to maintain multiple versions simultaneously. For backward compatibility, we'd:

1. **Maintain old versions** for a deprecation period
2. **Add new fields** without breaking existing clients
3. **Use feature flags** for gradual rollouts
4. **Provide migration guides** for major version changes"

---

## Data Model Validation

**Candidate's Sanity Check**:

### Query Performance Analysis
"Let me validate that our schema supports our key queries efficiently:

1. **Get user timeline**: `SELECT * FROM tweets WHERE user_id = ? ORDER BY created_at DESC LIMIT 20`
   - **Index**: `idx_user_created` supports this perfectly

2. **Get home timeline**: More complex - need tweets from all followed users
   - **Query**: `SELECT t.* FROM tweets t JOIN follows f ON t.user_id = f.followee_id WHERE f.follower_id = ? ORDER BY t.created_at DESC LIMIT 20`
   - **Challenge**: This will be slow at scale - need optimization

3. **Check follow relationship**: `SELECT 1 FROM follows WHERE follower_id = ? AND followee_id = ?`
   - **Index**: Primary key supports this efficiently

### Storage Estimation Validation
```
Users: 500M × 1KB = 500GB
Tweets: 200M/day × 365 days × 1KB = 73TB/year
Follows: 100M users × 200 follows × 16 bytes = 320GB
Total: ~75TB/year (matches our earlier estimate)
```

### Bottleneck Identification
1. **Timeline generation**: Most complex query, will need optimization
2. **Counter updates**: Need eventual consistency strategy
3. **Hot user problem**: Popular users will create hotspots

**Interviewer**: "Great analysis. You've identified the timeline generation as the key challenge, which is exactly right. Ready to move on to the high-level architecture?"

---

## Entity & API Design Summary

✅ **Core entities defined**: User, Tweet, Follow relationships  
✅ **Schema optimized**: Proper indexes and constraints  
✅ **ID strategy chosen**: Snowflake IDs for distributed generation  
✅ **APIs designed**: RESTful, consistent, paginated  
✅ **Performance considered**: Denormalized counters, efficient indexes  
✅ **Bottlenecks identified**: Timeline generation needs optimization

**Key Design Decisions:**
- **Denormalized counters** for performance
- **Snowflake IDs** for distributed, time-ordered generation
- **Cursor-based pagination** for real-time consistency
- **Eventual consistency** for non-critical counters

**Next**: High-level architecture design to see how these entities fit into a scalable system.