# Twitter System Design: Non-Functional Requirements & Scale

## Interview Conversation

**Interviewer**: "Now that we have our functional requirements, let's talk about scale. What kind of numbers are we looking at for a Twitter-like system?"

**Candidate**: "Great question. Let me approach this systematically by first establishing the scale we're designing for, then deriving the non-functional requirements from that scale.

### Scale Assumptions

Let me start with some reasonable assumptions about Twitter's scale:

**User Base:**
- Total registered users: ~500 million
- Daily Active Users (DAU): ~100 million  
- Peak concurrent users: ~20 million

Does this scale sound reasonable for our design exercise?"

**Interviewer**: "Those numbers are in the right ballpark. Let's use them as our baseline."

**Candidate**: "Perfect. Now let me work through the capacity calculations step by step, showing my reasoning for each."

---

## Capacity Estimation Deep Dive

### 1. Write Operations (Tweet Posting)

**Candidate's Calculation Process**:

"Let me estimate tweet volume:

**Assumptions:**
- Average tweets per user per day: 2 tweets
- Some users are very active (100+ tweets/day), others rarely tweet
- 80/20 rule: 20% of users generate 80% of content

**Calculations:**
```
Daily tweets = DAU × average tweets per user
Daily tweets = 100M × 2 = 200M tweets/day

Tweets per second (average) = 200M / (24 × 3600) = 2,315 TPS
Peak TPS = Average TPS × 3 = ~7,000 TPS
```

**Validation Check:**
'Does 200M tweets per day seem reasonable? That's about 2 tweets per active user, which feels right given that many users are lurkers and only a subset are active posters.'

**Interviewer**: "That math looks solid. What about read operations?"

### 2. Read Operations (Timeline Generation)

**Candidate's Analysis**:

"Timeline reads are much more frequent than writes. Let me break this down:

**Timeline Read Patterns:**
- Average timeline refreshes per user per day: 50
- Each refresh loads ~20 tweets
- Users also browse profiles, individual tweets

**Calculations:**
```
Timeline requests per day = DAU × timeline refreshes per day
Timeline requests per day = 100M × 50 = 5B requests/day

Timeline QPS (average) = 5B / (24 × 3600) = 57,870 QPS
Peak Timeline QPS = 57,870 × 3 = ~175,000 QPS
```

**Additional Read Operations:**
- Profile page views: ~10,000 QPS
- Individual tweet views: ~20,000 QPS
- Search queries: ~5,000 QPS

**Total Read QPS: ~200,000 QPS at peak**

**Read/Write Ratio: ~30:1** (which is typical for social media platforms)

**Interviewer**: "Good analysis. The read-heavy nature is important for our design. What about storage requirements?"

### 3. Storage Estimation

**Candidate's Detailed Breakdown**:

"Let me calculate storage needs for different data types:

#### Tweet Storage
```
Average tweet size:
- Text content: 280 chars × 2 bytes = 560 bytes
- Metadata (user_id, timestamp, tweet_id, etc.): 200 bytes
- Total per tweet: ~800 bytes ≈ 1KB

Daily storage for tweets:
200M tweets/day × 1KB = 200GB/day

Annual tweet storage:
200GB × 365 = 73TB/year
```

#### User Data Storage
```
User profile data:
- Basic info (username, email, bio, etc.): ~2KB per user
- Total users: 500M × 2KB = 1TB

Social graph (follow relationships):
- Average follows per user: 200
- Each relationship: 16 bytes (follower_id + followee_id)
- Total relationships: 100M users × 200 follows = 20B relationships
- Storage: 20B × 16 bytes = 320GB
```

#### Total Storage Summary
```
Year 1: 73TB (tweets) + 1TB (users) + 0.32TB (social graph) = ~75TB
Year 5: 365TB (tweets) + 1TB (users) + 0.32TB (social graph) = ~370TB

With replication (3x): ~1.1PB after 5 years
```

**Interviewer**: "Those numbers help us understand the scale. What about bandwidth and latency requirements?"

### 4. Bandwidth Requirements

**Candidate's Analysis**:

"Let me calculate bandwidth needs:

#### Write Bandwidth
```
Tweet writes: 7,000 TPS × 1KB = 7MB/s
User updates, follows: ~1MB/s
Total write bandwidth: ~8MB/s
```

#### Read Bandwidth
```
Timeline reads: 175,000 QPS × 20KB (20 tweets × 1KB) = 3.5GB/s
Profile/individual tweet reads: 35,000 QPS × 1KB = 35MB/s
Total read bandwidth: ~3.5GB/s
```

**Total Bandwidth: ~3.5GB/s (heavily read-dominated)**

### 5. Memory Requirements (Caching)

**Candidate's Caching Strategy**:

"For optimal performance, we'll need significant caching:

#### Hot Data Identification
- Recent tweets (last 24 hours): 200GB
- Active user timelines: Top 10M users × 100 tweets × 1KB = 1TB
- User profiles (frequently accessed): 50M users × 2KB = 100GB
- Social graph (hot relationships): ~50GB

**Total cache requirement: ~1.5TB distributed across cache clusters**

---

## Non-Functional Requirements Definition

**Candidate**: "Based on this capacity analysis, here are our non-functional requirements:

### Performance Requirements

#### Latency Targets
- **Timeline loading**: < 200ms (P95)
- **Tweet posting**: < 100ms (P95)  
- **Profile loading**: < 150ms (P95)
- **Follow/unfollow**: < 50ms (P95)

#### Throughput Targets
- **Write operations**: 10,000 TPS (with headroom)
- **Read operations**: 250,000 QPS (with headroom)
- **Timeline generation**: 200,000 QPS

### Availability Requirements

#### Uptime Targets
- **Overall system availability**: 99.9% (8.76 hours downtime/year)
- **Core features availability**: 99.95% (4.38 hours downtime/year)
- **Graceful degradation**: System should degrade gracefully under load

#### Disaster Recovery
- **RTO (Recovery Time Objective)**: < 1 hour
- **RPO (Recovery Point Objective)**: < 5 minutes of data loss

### Scalability Requirements

#### Growth Planning
- **User growth**: Support 10x user growth (1B users)
- **Tweet volume**: Handle 10x tweet volume (2B tweets/day)
- **Geographic expansion**: Multi-region deployment capability

#### Auto-scaling
- **Horizontal scaling**: Add/remove servers based on load
- **Database scaling**: Shard data across multiple databases
- **Cache scaling**: Distribute cache across multiple nodes

### Consistency Requirements

#### Data Consistency
- **Tweet posting**: Strong consistency (user sees their tweet immediately)
- **Timeline updates**: Eventual consistency (few seconds delay acceptable)
- **Follow relationships**: Strong consistency
- **Counters (likes, retweets)**: Eventual consistency acceptable

### Security Requirements

#### Authentication & Authorization
- **User authentication**: Secure login/logout
- **API security**: Rate limiting, authentication tokens
- **Data privacy**: User data protection

#### Content Security
- **Input validation**: Prevent malicious content
- **Rate limiting**: Prevent spam and abuse
- **DDoS protection**: Handle traffic spikes and attacks

**Interviewer**: "Excellent breakdown. I particularly like how you've thought about consistency requirements - that's often overlooked. The eventual consistency for timelines but strong consistency for posting is a good trade-off."

---

## Design Implications

**Candidate's Strategic Thinking**:

"These non-functional requirements have several key implications for our architecture:

### 1. Read-Heavy Architecture
- **Implication**: Need extensive caching and read replicas
- **Design choice**: Cache-first architecture with multiple cache layers

### 2. Timeline Generation Challenge  
- **Implication**: 200K QPS for timeline generation is our biggest bottleneck
- **Design choice**: Need to pre-compute timelines vs. compute on-demand

### 3. Global Scale
- **Implication**: Need geographic distribution for latency
- **Design choice**: Multi-region deployment with CDN

### 4. Consistency Trade-offs
- **Implication**: Can't have strong consistency everywhere at this scale
- **Design choice**: Eventual consistency for non-critical paths

### 5. Storage Growth
- **Implication**: 1PB+ storage needs partitioning strategy
- **Design choice**: Time-based and user-based sharding

**Interviewer**: "Those are exactly the right implications to draw. You're thinking like a staff engineer - connecting requirements to architectural decisions. Ready to move on to entities and API design?"

---

## Requirements Validation

**Candidate's Sanity Check**:

"Let me quickly validate these numbers against real-world systems:

### Comparison with Known Systems
- **Twitter actual scale**: ~500M users, ~500M tweets/day
- **Our estimates**: 500M users, 200M tweets/day
- **Assessment**: Our estimates are conservative, which is good for design

### Bottleneck Analysis
1. **Timeline generation**: 200K QPS - This will be our primary challenge
2. **Database writes**: 10K TPS - Manageable with proper sharding
3. **Storage growth**: 1PB in 5 years - Need distributed storage strategy
4. **Cache requirements**: 1.5TB - Need distributed caching

### Risk Assessment
- **Highest risk**: Timeline generation at scale
- **Medium risk**: Database sharding strategy
- **Lower risk**: Basic CRUD operations

This analysis will guide our architectural decisions in the next phase."

**Interviewer**: "Perfect. You've set up a solid foundation with clear requirements and realistic scale estimates. Let's design the entities and APIs next."

---

## Non-Functional Requirements Summary

✅ **Scale established**: 100M DAU, 200M tweets/day  
✅ **Performance targets defined**: <200ms timeline, <100ms posting  
✅ **Availability requirements set**: 99.9% uptime  
✅ **Consistency model chosen**: Strong for writes, eventual for reads  
✅ **Capacity calculated**: 10K write TPS, 250K read QPS  
✅ **Storage estimated**: 1PB over 5 years  
✅ **Design implications identified**: Read-heavy, cache-first architecture

**Next**: Entity design and API specification to define our data model and interfaces.