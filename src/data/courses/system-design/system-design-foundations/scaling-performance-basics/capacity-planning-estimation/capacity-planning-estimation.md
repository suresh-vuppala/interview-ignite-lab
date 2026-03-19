
## Interview Focus

**Critical Interview Questions:**
- "Estimate the storage needed for YouTube videos"
- "How much bandwidth does Netflix need?"
- "Calculate the number of servers required for 1 billion users"
- "Design Twitter's infrastructure - estimate QPS, storage, bandwidth"

---

## Why Capacity Planning Matters

### In Technical Interviews
> **Key Point:** Capacity planning demonstrates your ability to think analytically about real-world system constraints and make data-driven architectural decisions.

- **Tests analytical thinking** and problem-solving approach
- **Shows understanding** of scale and system constraints  
- **Demonstrates practical experience** with real-world systems
- **Foundation for system design** - drives architecture decisions

### In Real Systems
> **Important:** Proper capacity planning can save millions in infrastructure costs and prevent catastrophic system failures.

- **Cost optimization** - avoid over/under-provisioning
- **Performance planning** - ensure system meets SLAs
- **Scalability roadmap** - plan for growth
- **Risk mitigation** - prevent system failures

---

## Essential Numbers to Memorize

> **Critical:** These numbers form the foundation of all capacity estimations. Memorize the orders of magnitude, not exact values.

### Time & Latency
```
L1 cache reference                         :        0.5 ns
Branch mispredict                          :          5 ns
L2 cache reference                         :          7 ns
Mutex lock/unlock                          :         25 ns
Main memory reference                      :        100 ns
Compress 1 KB with Zippy                   :      3,000 ns   = 3 μs
Send 1 KB over 1 Gbps                      :     10,000 ns   = 10 μs
Read 4 KB randomly from SSD                :    150,000 ns   = 150 μs
Read 1 MB sequentially from memory         :    250,000 ns   = 250 μs
Round trip within same datacenter          :    500,000 ns   = 0.5 ms
Read 1 MB sequentially from SSD            :  1,000,000 ns   = 1 ms
Disk seek                                  : 10,000,000 ns  = 10 ms
Read 1 MB sequentially from disk           : 20,000,000 ns  = 20 ms
Send packet CA → Netherlands → CA          :150,000,000 ns  = 150 ms
```

### Storage & Data
> **Remember:** Use powers of 10 for simplicity in interviews (1KB = 1,000 bytes, not 1,024)

```
1 Byte = 8 bits
1 KB = 1,000 bytes (10^3)
1 MB = 1,000 KB = 10^6 bytes
1 GB = 1,000 MB = 10^9 bytes
1 TB = 1,000 GB = 10^12 bytes
1 PB = 1,000 TB = 10^15 bytes

ASCII character: 1 byte
Unicode character: 1-4 bytes
Integer (32-bit): 4 bytes
Long (64-bit): 8 bytes
UUID: 16 bytes
Timestamp: 8 bytes
```

### Network & Bandwidth
```
1 Mbps = 125 KB/s
1 Gbps = 125 MB/s
Typical home internet: 100 Mbps
Data center network: 10-100 Gbps
CDN edge server: 1-10 Gbps
```

### Scale References
> **Pro Tip:** Use these real-world numbers to validate your estimates

```
Seconds in a day: 86,400 (~100K)
Seconds in a year: 31,536,000 (~30M)
Google searches per day: 8.5 billion
Facebook DAU: 2 billion
YouTube hours watched per day: 1 billion
Twitter tweets per day: 500 million
```

---

## Step-by-Step Estimation Framework

> **Golden Rule:** Always start with clarifying requirements and stating assumptions explicitly.

### 1. Clarify Requirements
**Ask these questions first:**
- **What are we estimating?** (Storage, QPS, Bandwidth, Servers)
- **What's the scale?** (Users, requests, data size)
- **What's the time frame?** (Daily, monthly, yearly)
- **What are the constraints?** (Read/write ratio, peak traffic)

### 2. Make Reasonable Assumptions
**State your assumptions clearly:**
- **User behavior patterns**
- **Growth rates**
- **System characteristics**
- **Infrastructure capabilities**

### 3. Calculate Step by Step
**Show your work:**
- **Start with basic numbers**
- **Build up complexity gradually**
- **Show your work clearly**
- **Round numbers for simplicity**

### 4. Validate and Adjust
**Sanity check everything:**
- **Sanity check results**
- **Consider peak vs average**
- **Account for growth**
- **Add safety margins**

---

## Interview Examples

### Example 1: YouTube Storage Estimation

**Question**: "Estimate how much storage YouTube needs for videos uploaded daily."

> **Key Insight:** Break down the problem into upload rate, video size, and quality variations.

**Solution**:
```
1. Assumptions:
   - 500 hours of video uploaded per minute
   - Average video quality: 1080p
   - Average video size: 100 MB per minute

2. Calculations:
   Daily uploads = 500 hours/min × 60 min/hour × 24 hours
                 = 720,000 hours per day
   
   Storage per day = 720,000 hours × 60 min/hour × 100 MB/min
                   = 4.32 billion MB
                   = 4.32 TB per day
   
   Annual storage = 4.32 TB × 365 days = 1,577 TB ≈ 1.6 PB per year

3. With multiple qualities (360p, 720p, 1080p, 4K):
   Total storage ≈ 1.6 PB × 4 = 6.4 PB per year
```

### Example 2: Twitter QPS Estimation

**Question**: "Calculate Twitter's read and write QPS."

> **Important:** Notice the read-to-write ratio - this is typical for social media platforms.

**Solution**:
```
1. Assumptions:
   - 300M daily active users
   - Each user tweets 2 times per day on average
   - Each user reads 100 tweets per day
   - Peak traffic is 3x average

2. Write QPS:
   Daily tweets = 300M users × 2 tweets/user = 600M tweets/day
   Average write QPS = 600M / (24 × 3600) = 6,944 QPS ≈ 7K QPS
   Peak write QPS = 7K × 3 = 21K QPS

3. Read QPS:
   Daily reads = 300M users × 100 reads/user = 30B reads/day
   Average read QPS = 30B / (24 × 3600) = 347,222 QPS ≈ 350K QPS
   Peak read QPS = 350K × 3 = 1M QPS

4. Read:Write Ratio = 350K:7K = 50:1
```

### Example 3: WhatsApp Server Estimation

**Question**: "How many servers does WhatsApp need to handle 2 billion users?"

> **Key Learning:** Connection handling often dominates server requirements for messaging apps.

**Solution**:
```
1. Assumptions:
   - 2B registered users, 1B daily active users
   - Each user sends 50 messages per day
   - Each server can handle 10K concurrent connections
   - Peak concurrent users: 500M (50% of DAU)

2. Message QPS:
   Daily messages = 1B users × 50 messages = 50B messages/day
   Average QPS = 50B / (24 × 3600) = 578K QPS
   Peak QPS = 578K × 3 = 1.7M QPS

3. Connection Servers:
   Concurrent connections = 500M users
   Servers needed = 500M / 10K = 50,000 servers

4. Message Processing Servers:
   Assuming each server handles 5K QPS:
   Servers needed = 1.7M QPS / 5K = 340 servers

5. Total servers ≈ 50,000 (connection handling dominates)
```

---

## Common Estimation Patterns

> **Master These:** These patterns apply to 90% of estimation problems in interviews.

### Storage Estimation Pattern
```
1. Identify data types (users, posts, media, etc.)
2. Estimate size per record
3. Calculate total records
4. Add metadata overhead (20-30%)
5. Consider replication factor (3x)
6. Plan for growth (5 years)

Formula: Storage = Records × Size × Overhead × Replication × Growth
```

### QPS Estimation Pattern
```
1. Daily active users
2. Actions per user per day
3. Convert to average QPS
4. Apply peak multiplier (2-5x)
5. Consider read/write ratio

Formula: QPS = (DAU × Actions/day) / (24 × 3600) × Peak_multiplier
```

### Bandwidth Estimation Pattern
```
1. Calculate data transfer per request
2. Multiply by QPS
3. Consider compression (30-50% reduction)
4. Add protocol overhead (10-20%)

Formula: Bandwidth = QPS × Data_per_request × (1 - compression) × (1 + overhead)
```

### Memory Estimation Pattern
> **Key for Caching:** Memory requirements often determine system performance.

```
1. Identify cacheable data (hot data, user sessions, etc.)
2. Calculate cache hit ratio target (80-95%)
3. Estimate memory per cached item
4. Apply Pareto principle (20% of data = 80% of requests)
5. Add overhead for data structures (20-30%)
6. Plan for peak usage

Formula: Memory = hot_data_size × cache_ratio × overhead × peak_multiplier

Example Cache Sizing:
- User sessions: 1KB × 1M active users = 1GB
- Product catalog: 10KB × 100K products × 20% hot = 200MB
- Search results: 50KB × 10K queries × 1 hour TTL = 500MB
```

---

## Advanced Estimation Techniques

### 1. Pareto Principle (80/20 Rule)
> **Apply This:** Use the 80/20 rule for cache sizing and resource allocation decisions.

- **80% of traffic** comes from **20% of users**
- **80% of data access** focuses on **20% of content**
- Use for cache sizing and hot data estimation

### 2. Peak Traffic Modeling
> **Critical:** Always plan for peak traffic, not average traffic.

```
Daily peak: 3-5x average
Weekly peak: 2x daily average
Seasonal peak: 10x average (Black Friday, New Year)
Viral content: 100x average (breaking news, viral videos)
```

### 3. Geographic Distribution
```
North America: 25% of global traffic
Europe: 20%
Asia-Pacific: 45%
Others: 10%

Peak hours vary by timezone (+8 hours difference)
```

### 4. Growth Modeling
> **Plan Ahead:** Always include growth projections in your estimates.

```
Linear growth: +X users per month
Exponential growth: 2x every Y months
S-curve growth: slow → fast → plateau

Plan for 5-year capacity with 2x safety margin
```

---

## Real-World Infrastructure Translation

> **Bridge the Gap:** How estimates translate to actual infrastructure decisions.

### From Estimates to Architecture

#### Example: Social Media Platform (100M DAU)
**Estimates:**
```
QPS: 500K reads, 50K writes
Storage: 10TB new data/day
Bandwidth: 50 Gbps peak
Memory: 2TB cache needed
```

**Infrastructure Translation:**
```
Web Tier: 200 servers (2.5K QPS each)
Database: 10 read replicas + 2 write masters
Cache: 20 Redis instances (100GB each)
CDN: Global distribution, 100TB cache
Storage: Distributed file system, 3x replication
Network: 100 Gbps backbone, load balancers
```

#### Cost Implications
```
Servers: $200/month × 200 = $40K/month
Database: $500/month × 12 = $6K/month
Cache: $100/month × 20 = $2K/month
CDN: $0.05/GB × 1PB = $50K/month
Total: ~$100K/month infrastructure
```

### Scaling Decision Points

#### When to Scale Vertically
```
CPU utilization > 70% consistently
Memory usage > 80%
Disk I/O becoming bottleneck
Simple application architecture
```

#### When to Scale Horizontally
```
Vertical scaling hits hardware limits
Need geographic distribution
Fault tolerance requirements
Cost optimization (commodity hardware)
```

---

## Common Estimation Mistakes

> **Avoid These Pitfalls:** Learn from common interview failures.

### Calculation Errors

#### **Mistake 1: Confusing Bits and Bytes**
```
Wrong: 1 Gbps = 1 GB/s
Right: 1 Gbps = 125 MB/s (divide by 8)

Wrong: 100 Mbps can transfer 100 MB/s
Right: 100 Mbps can transfer 12.5 MB/s
```

#### **Mistake 2: Ignoring Peak Traffic**
```
Wrong: Plan for average load only
Right: Plan for 3-5x peak load

Example: Average 10K QPS, plan for 50K QPS
```

#### **Mistake 3: Forgetting Overhead**
```
Wrong: Pure data size calculations
Right: Add 20-30% for metadata, indexes, replication

Example: 1TB data → 1.3TB with overhead → 3.9TB with 3x replication
```

### Architectural Oversights

#### **Mistake 4: Single Point of Failure**
```
Wrong: One database for 1M users
Right: Master-slave setup with failover

Wrong: Single load balancer
Right: Multiple load balancers with health checks
```

#### **Mistake 5: Ignoring Geographic Distribution**
```
Wrong: Single datacenter for global users
Right: Multi-region deployment with CDN

Latency impact: 200ms vs 50ms response time
```

#### **Mistake 6: Underestimating Read/Write Ratios**
```
Wrong: Assume 1:1 read/write ratio
Right: Most systems are 10:1 to 100:1 read-heavy

Example: Social media is typically 100:1 read/write
```

### Operational Mistakes

#### **Mistake 7: Forgetting Monitoring Overhead**
```
Wrong: Pure application resource calculation
Right: Add 10-15% for monitoring, logging, metrics
```

#### **Mistake 8: No Growth Planning**
```
Wrong: Design for current scale only
Right: Plan for 2-5 years of growth

Example: Design for 10x current load
```

#### **Mistake 9: Ignoring Consistency Requirements**
```
Wrong: Assume eventual consistency is always acceptable
Right: Identify strong consistency requirements

Example: Financial transactions need ACID properties
```

---

## Cost Estimation Framework

> **Business Impact:** Translate technical estimates to budget planning.

### Cloud Cost Components

#### **Compute Costs**
```
AWS EC2 m5.large: $0.096/hour = $70/month
Google Cloud n1-standard-2: $0.095/hour = $69/month
Azure Standard_D2s_v3: $0.096/hour = $70/month

Rule of thumb: $35-100/month per server
```

#### **Storage Costs**
```
SSD storage: $0.10-0.20/GB/month
HDD storage: $0.04-0.08/GB/month
Object storage: $0.02-0.05/GB/month

Example: 10TB SSD = $1,000-2,000/month
```

#### **Network Costs**
```
Data transfer out: $0.05-0.12/GB
CDN: $0.02-0.08/GB
Load balancer: $20-50/month

Example: 100TB/month transfer = $2,000-12,000/month
```

### Cost Optimization Strategies

#### **Right-sizing Resources**
```
Monitor actual usage vs provisioned
Use auto-scaling to match demand
Reserved instances for predictable workloads
Spot instances for fault-tolerant workloads
```

#### **Storage Optimization**
```
Tiered storage: Hot/Warm/Cold data
Compression: 30-70% storage reduction
Deduplication: 20-50% reduction
Lifecycle policies: Auto-archive old data
```

#### **Network Optimization**
```
CDN for static content: 80% bandwidth reduction
Compression: 50-90% transfer reduction
Regional caching: Reduce cross-region traffic
Peering agreements: Reduce transit costs
```

### Cost Estimation Example

#### **E-commerce Platform (1M DAU)**
```
Estimates:
- 50K QPS peak
- 5TB new data/day
- 20 Gbps bandwidth
- 500GB cache

Infrastructure:
- 50 web servers: $3,500/month
- 5 database servers: $2,500/month
- 10 cache servers: $1,000/month
- CDN: $5,000/month
- Storage (100TB): $8,000/month
- Network: $3,000/month

Total: $23,000/month = $276K/year
Per user cost: $0.23/month
```

---

## Interview Tips & Best Practices

### Do's
> **Success Strategy:** Be transparent about your thought process and assumptions.

- **State assumptions clearly** - "I'm assuming..."
- **Show your calculations** - write them out
- **Round numbers** - use 100K instead of 97,234
- **Think out loud** - explain your reasoning
- **Validate results** - "Does this make sense?"
- **Consider edge cases** - peak traffic, viral content
- **Plan for growth** - "In 5 years, we'll need..."

### Don'ts
> **Avoid These Mistakes:** Common pitfalls that can derail your interview.

- **Don't memorize exact numbers** - focus on orders of magnitude
- **Don't be afraid to estimate** - it's called "back-of-envelope" for a reason
- **Don't ignore constraints** - budget, latency, consistency requirements
- **Don't forget operational overhead** - `monitoring`, `backups`, `failover`

### Sample Phrases for Interviews
- "Let me break this down `step by step`..."
- "I'll make some `reasonable assumptions` here..."
- "This gives us an `order of magnitude` of..."
- "Let me `sanity check` this number..."
- "We should plan for `peak traffic` which is typically..."
- "Adding a `safety margin` of 2x for unexpected growth..."

---

## Capacity Planning Checklist

### Before the Interview
- **Memorize key `latency numbers`**
- **Practice common `estimation problems`**
- **Understand `orders of magnitude`**
- **Know typical `system scales`** (Google, Facebook, etc.)

### During the Interview
- **Clarify `requirements` and `constraints`**
- **State `assumptions` explicitly**
- **Calculate `step by step`**
- **Validate results with `sanity checks`**
- **Consider `peak traffic` and `growth`**
- **Discuss `trade-offs` and `alternatives`**

### Key Metrics to Estimate
- **`QPS`** (Queries Per Second)
- **`Storage`** (Total data size)
- **`Bandwidth`** (Network throughput)
- **`Servers`** (Number of machines needed)
- **`Memory`** (Cache and buffer requirements)
- **`Cost`** (Infrastructure expenses)

---

## Practice Problems

> **Learn by Doing:** Work through these problems to master capacity planning skills.

### Problem 1: Instagram Photo Storage

**Question**: "Estimate the `storage requirements` for Instagram photos uploaded daily."

**Your Task**: Calculate `daily` and `annual` storage needs.

**Hints**:
- Consider number of `daily active users`
- Average `photos uploaded` per user per day
- Photo `file sizes` (different resolutions)
- `Metadata` and `thumbnails`

**Solution**:
```
1. Assumptions:
   - 500M daily active users
   - Each user uploads 2 photos per day on average
   - Original photo: 2MB, compressed: 500KB
   - 3 thumbnail sizes: 50KB, 20KB, 10KB
   - Metadata: 1KB per photo

2. Calculations:
   Daily photos = 500M users × 2 photos = 1B photos/day
   
   Storage per photo:
   - Original: 500KB
   - Thumbnails: 50KB + 20KB + 10KB = 80KB
   - Metadata: 1KB
   - Total per photo: 581KB ≈ 600KB
   
   Daily storage = 1B photos × 600KB = 600TB/day
   Annual storage = 600TB × 365 = 219PB/year
   
   With 3x replication: 219PB × 3 = 657PB/year
```

---

### Problem 2: Zoom Video Conferencing

**Question**: "Calculate the `bandwidth requirements` for Zoom during `peak usage` (COVID-19 levels)."

**Your Task**: Estimate total `bandwidth` needed globally.

**Hints**:
- Peak `concurrent` meeting participants
- `Video quality` settings
- `Audio` vs `video` bandwidth
- `Upload` vs `download` requirements

**Solution**:
```
1. Assumptions:
   - 300M peak concurrent participants
   - Average meeting size: 8 people
   - Video quality: 720p HD (1.5 Mbps per stream)
   - Audio: 64 kbps per stream
   - 70% video calls, 30% audio-only

2. Calculations:
   Video calls: 300M × 0.7 = 210M participants
   Audio calls: 300M × 0.3 = 90M participants
   
   Video bandwidth per participant:
   - Upload: 1.5 Mbps (own video)
   - Download: 1.5 Mbps × 7 others = 10.5 Mbps
   - Total per participant: 12 Mbps
   
   Audio bandwidth per participant:
   - Upload: 64 kbps
   - Download: 64 kbps × 7 others = 448 kbps
   - Total per participant: 512 kbps ≈ 0.5 Mbps
   
   Total bandwidth:
   - Video: 210M × 12 Mbps = 2.52 Tbps
   - Audio: 90M × 0.5 Mbps = 45 Gbps
   - Total: 2.52 Tbps + 0.045 Tbps = 2.565 Tbps
```

---

### Problem 3: Spotify Music Streaming

**Question**: "Estimate Spotify's global `bandwidth` and `storage` requirements."

**Your Task**: Calculate both `bandwidth` for streaming and `storage` for music library.

**Hints**:
- Number of `active users`
- `Listening hours` per user
- Audio quality `bitrates`
- `Music library` size
- `Cache hit ratios`

**Solution**:
```
1. Assumptions:
   - 400M active users globally
   - Peak concurrent: 100M users (25%)
   - Average listening: 2 hours/day per user
   - Audio quality: 320 kbps (high quality)
   - Music library: 80M songs
   - Average song: 3.5 minutes, 8MB at 320kbps
   - CDN cache hit rate: 85%

2. Bandwidth Calculation:
   Peak streaming = 100M users × 320 kbps = 32 Tbps
   Origin bandwidth (cache miss) = 32 Tbps × 0.15 = 4.8 Tbps
   
3. Storage Calculation:
   Music library = 80M songs × 8MB = 640TB
   Multiple qualities (96k, 160k, 320k): 640TB × 3 = 1.92PB
   With replication (3x): 1.92PB × 3 = 5.76PB
   
   CDN cache storage (hot content 20%):
   Hot songs = 80M × 0.2 = 16M songs
   Cache storage = 16M × 8MB × 3 qualities = 384TB per region
   Global CDN (50 regions): 384TB × 50 = 19.2PB
```

---

### Problem 4: Uber Ride Matching

**Question**: "Calculate the `QPS` and `server requirements` for Uber's ride matching system."

**Your Task**: Estimate `processing requirements` for real-time ride matching.

**Hints**:
- Number of active `riders` and `drivers`
- `Ride requests` per hour
- `Location updates` frequency
- `Matching algorithm` complexity

**Solution**:
```
1. Assumptions:
   - 50M active users globally
   - Peak hour: 10M concurrent users (20%)
   - 8M riders, 2M drivers during peak
   - Ride requests: 500K per hour during peak
   - Location updates: Every 5 seconds for active users
   - Each server handles 5K QPS

2. QPS Calculations:
   Ride requests = 500K/hour ÷ 3600 = 139 QPS
   
   Location updates:
   - Active users: 10M
   - Update frequency: Every 5 seconds
   - Location QPS = 10M ÷ 5 = 2M QPS
   
   Matching requests (triggered by location updates):
   - Only for active riders: 8M
   - Matching QPS = 8M ÷ 5 = 1.6M QPS
   
   Total QPS = 139 + 2M + 1.6M = 3.6M QPS
   
3. Server Requirements:
   Servers needed = 3.6M QPS ÷ 5K QPS = 720 servers
   With 2x safety margin: 720 × 2 = 1,440 servers
```

---

### Problem 5: TikTok Video Platform

**Question**: "Design `capacity planning` for TikTok's video upload and streaming infrastructure."

**Your Task**: Calculate `storage`, `bandwidth`, and `processing` requirements.

**Hints**:
- `Daily active users`
- Videos `uploaded` vs `watched`
- Video processing (`transcoding`)
- Global `CDN` requirements
- `Mobile` vs `web` traffic

**Solution**:
```
1. Assumptions:
   - 1B daily active users
   - 10% upload videos (100M uploaders)
   - Each uploader posts 2 videos/day
   - Average video: 30 seconds, 50MB original
   - Watch ratio: 100:1 (views to uploads)
   - Peak concurrent viewers: 200M (20%)

2. Upload Requirements:
   Daily uploads = 100M × 2 = 200M videos/day
   Upload QPS = 200M ÷ 86,400 = 2,315 QPS
   Peak upload QPS = 2,315 × 5 = 11,575 QPS
   
3. Storage Requirements:
   Raw storage/day = 200M × 50MB = 10PB/day
   
   After transcoding (multiple qualities):
   - 480p: 15MB
   - 720p: 25MB  
   - 1080p: 50MB
   Total per video = 90MB
   
   Processed storage/day = 200M × 90MB = 18PB/day
   Annual storage = 18PB × 365 = 6.57EB/year
   
4. Streaming Bandwidth:
   Peak viewers = 200M
   Average bitrate = 2 Mbps (mobile optimized)
   Peak bandwidth = 200M × 2 Mbps = 400 Tbps
   
   With CDN (95% cache hit):
   Origin bandwidth = 400 Tbps × 0.05 = 20 Tbps
   
5. Processing Requirements:
   Transcoding: 200M videos/day
   Processing time: 2x video length = 1 minute per video
   Total processing = 200M minutes/day = 138,889 hours/day
   Servers needed (24/7) = 138,889 ÷ 24 = 5,787 transcoding servers
```

---

### Problem 6: LinkedIn Professional Network

**Question**: "Estimate LinkedIn's `infrastructure requirements` for posts, connections, and messaging."

**Your Task**: Calculate `QPS`, `storage`, and `bandwidth` for professional social network.

**Hints**:
- `Professional` user behavior patterns
- Post types (`text`, `images`, `videos`)
- `Connection requests` and `messaging`
- `Job search` and `recommendations`

**Solution**:
```
1. Assumptions:
   - 800M registered users, 300M monthly active
   - 100M daily active users
   - Each user: 5 posts viewed, 0.1 posts created daily
   - Messages: 2 per active user per day
   - Connection requests: 0.5 per user per day
   - Job searches: 10% of users search daily

2. QPS Calculations:
   Post reads = 100M × 5 ÷ 86,400 = 5,787 QPS
   Post writes = 100M × 0.1 ÷ 86,400 = 116 QPS
   Messages = 100M × 2 ÷ 86,400 = 2,315 QPS
   Connections = 100M × 0.5 ÷ 86,400 = 579 QPS
   Job searches = 10M × 5 searches ÷ 86,400 = 579 QPS
   
   Total QPS = 5,787 + 116 + 2,315 + 579 + 579 = 9,376 QPS
   Peak QPS = 9,376 × 3 = 28,128 QPS
   
3. Storage Requirements:
   User profiles = 800M × 10KB = 8TB
   Posts (text) = 10M/day × 500 bytes × 365 × 5 years = 9.1TB
   Messages = 200M/day × 200 bytes × 365 × 2 years = 29.2TB
   Connections = 800M users × 500 connections × 100 bytes = 40TB
   
   Total core data ≈ 87TB
   With indexes and replication (5x): 435TB
   
4. Bandwidth Requirements:
   Average response size = 50KB (rich content)
   Bandwidth = 28,128 QPS × 50KB = 1.4 GB/s = 11.2 Gbps
   
   With CDN for static content (80% reduction):
   Origin bandwidth = 11.2 Gbps × 0.2 = 2.24 Gbps
```

---

## References and Further Reading

### Performance Numbers & Latency
| Resource | Description |
|----------|-------------|
| [Latency Numbers Every Programmer Should Know](https://gist.github.com/jboner/2841832) | Essential latency reference for capacity planning |
| [Numbers Everyone Should Know](https://everythingisdata.wordpress.com/2009/10/17/numbers-everyone-should-know/) | Scale and performance numbers |
| [Jeff Dean's Performance Insights](https://static.googleusercontent.com/media/research.google.com/en//people/jeff/stanford-295-talk.pdf) | Google's performance insights |

### System Design & Architecture
| Resource | Description |
|----------|-------------|
| [High Scalability](http://highscalability.com/) | Real-world architecture case studies |
| [AWS Well-Architected Framework](https://docs.aws.amazon.com/wellarchitected/latest/framework/welcome.html) | Performance efficiency pillar |
| [Google Cloud Architecture Center](https://cloud.google.com/architecture) | Scalability patterns and capacity planning |
| [System Design Primer](https://github.com/donnemartin/system-design-primer) | Comprehensive capacity planning examples |

### Engineering Blogs
| Company | Resource | Focus |
|---------|----------|-------|
| Netflix | [Performance Under Load](https://netflixtechblog.com/performance-under-load-3e6fa9a60581) | Performance testing and capacity planning |
| Uber | [Real-time Data Infrastructure](https://eng.uber.com/real-time-exactly-once-ad-event-processing/) | Scale estimation examples |
| Facebook | [Scaling Memcached](https://engineering.fb.com/2008/05/20/core-data/scaling-memcached-at-facebook/) | Cache capacity planning |
| Instagram | [Infrastructure Scaling](https://instagram-engineering.com/what-powers-instagram-hundreds-of-instances-dozens-of-technologies-adf2e22da2ad) | Growth planning strategies |
| Twitter | [Timeline Architecture](https://blog.twitter.com/engineering/en_us/topics/architecture/2017/the-infrastructure-behind-twitter-scale) | QPS and storage estimation |
| Pinterest | [Scaling Journey](https://medium.com/pinterest-engineering/scaling-pinterest-from-0-to-10s-of-billions-of-page-views-a-month-in-two-years-4c94fabc5e3e) | Growth estimation case study |

### Cloud Provider Documentation
| Provider | Resource | Focus |
|----------|----------|-------|
| AWS | [Auto Scaling Guide](https://docs.aws.amazon.com/autoscaling/ec2/userguide/what-is-amazon-ec2-auto-scaling.html) | Capacity planning with auto scaling |
| Google Cloud | [Capacity Planning](https://cloud.google.com/compute/docs/instances/creating-instance-with-custom-machine-type) | Resource estimation guidelines |
| Azure | [Scalability Framework](https://docs.microsoft.com/en-us/azure/architecture/framework/scalability/capacity) | Performance and capacity guidance |

### Database Scaling
| Database | Resource | Focus |
|----------|----------|-------|
| MySQL | [Performance Optimization](https://dev.mysql.com/doc/refman/8.0/en/optimization.html) | Database performance optimization |
| PostgreSQL | [Performance Guide](https://wiki.postgresql.org/wiki/Performance_Optimization) | Database capacity planning |
| MongoDB | [Performance Analysis](https://docs.mongodb.com/manual/administration/analyzing-mongodb-performance/) | NoSQL scaling considerations |
| Redis | [Memory Optimization](https://redis.io/topics/memory-optimization) | Cache capacity planning |

### Tools & Calculators
| Tool | Purpose |
|------|----------|
| [AWS Pricing Calculator](https://calculator.aws/) | Infrastructure cost estimation |
| [Google Cloud Pricing Calculator](https://cloud.google.com/products/calculator) | Cloud resource planning |
| [Little's Law Calculator](https://www.littleslaw.com/) | Queueing theory for capacity planning |

---

## Related Topics for Deep Dive
- Performance Metrics (Latency, Throughput)
- Load Balancing Strategies  
- Database Sharding Calculations
- CDN Bandwidth Planning
- Auto-scaling Policies
- Cost Optimization Techniques