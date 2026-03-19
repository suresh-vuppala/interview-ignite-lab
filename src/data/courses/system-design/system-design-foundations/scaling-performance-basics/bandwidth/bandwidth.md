# Bandwidth

## Understanding Network Capacity

> **Engineering Foundation:** Bandwidth determines how much data your system can transfer and directly impacts user experience, costs, and global scalability.

**Core Learning Goals:**
- Master bandwidth as a fundamental network capacity metric
- Understand how bandwidth affects system design and user experience
- Learn to calculate bandwidth requirements for different applications
- Build intuition for bandwidth optimization and cost management
- Develop skills for planning global content delivery systems

---

## What Bandwidth Really Means

> **Engineering Reality:** Bandwidth is your network's data carrying capacity - it determines how fast users get content and how much infrastructure costs.

### Definition and Engineering Impact
**Bandwidth**: Maximum data transfer rate of a network connection, measured in bits per second

**Why Engineers Must Understand This**:
- **User experience** - Insufficient bandwidth causes slow loading and poor quality
- **Cost optimization** - Bandwidth is often the largest infrastructure expense
- **Global scaling** - Bandwidth planning enables worldwide service delivery
- **Performance bottlenecks** - Network capacity often limits system performance

### Bandwidth vs Related Concepts
| Concept | What It Measures | Engineering Focus | Real Impact |
|---------|------------------|-------------------|-------------|
| **`Bandwidth`** | Maximum transfer rate | Network capacity planning | "We need 10 Tbps for video streaming" |
| **`Throughput`** | Actual transfer achieved | Performance optimization | "We're using 8 Tbps of our 10 Tbps" |
| **`Latency`** | Time for data to travel | Response time optimization | "50ms to reach users globally" |
| **`Packet Loss`** | Data transmission reliability | Quality assurance | "0.1% loss affects video quality" |

---

## Bandwidth Fundamentals

### Units and Conversions

#### Common Units
```
1 Kbps = 1,000 bits per second
1 Mbps = 1,000,000 bits per second
1 Gbps = 1,000,000,000 bits per second
1 Tbps = 1,000,000,000,000 bits per second

Important: 1 Byte = 8 bits
1 Gbps = 125 MB/s (megabytes per second)
```

#### Real-World Examples
```
Dial-up modem: 56 Kbps
DSL: 1-100 Mbps
Cable internet: 10-1000 Mbps
Fiber internet: 100 Mbps - 10 Gbps
Enterprise network: 1-100 Gbps
Data center backbone: 100 Gbps - 400 Gbps
```

### Bandwidth Requirements by Application

#### Content Types
```
Text/JSON API: 1-10 KB per request
Images (compressed): 100 KB - 2 MB
Audio streaming: 128 Kbps - 320 Kbps
Video streaming (HD): 3-8 Mbps
Video streaming (4K): 15-25 Mbps
Video streaming (8K): 50-100 Mbps
```

#### Service Categories
```
Web browsing: 1-5 Mbps per user
Email: 0.1-1 Mbps per user
Video conferencing: 1-3 Mbps per user
Online gaming: 1-3 Mbps per user
File downloads: Limited by available bandwidth
Cloud backup: 10-100 Mbps sustained
```

---

## Bandwidth Calculation Methods

### Basic Bandwidth Formula

#### For Web Services
```
Bandwidth = QPS × Average Response Size × 8 (bits per byte)

Example: E-commerce API
- 10,000 QPS
- 50 KB average response
- Bandwidth = 10,000 × 50 KB × 8 = 4 Gbps
```

#### For Streaming Services
```
Bandwidth = Concurrent Users × Bitrate per Stream

Example: Video Streaming
- 1 million concurrent users
- 5 Mbps average bitrate
- Bandwidth = 1,000,000 × 5 Mbps = 5 Tbps
```

### Advanced Calculations

#### Peak vs Average Bandwidth
```
Average bandwidth: Based on typical usage patterns
Peak bandwidth: 3-5x average for web services
Burst bandwidth: 10x average for short periods

Planning rule: Provision for 2x peak bandwidth
```

#### Geographic Distribution
```
Global service bandwidth = Sum of regional bandwidth
Consider:
- Time zone differences (peak hours vary)
- Regional content preferences
- Local regulations and caching
```

---

## Real-World Bandwidth Examples

### Industry Scale Examples

#### Content Delivery Networks
```
Netflix: 15+ Tbps global bandwidth
YouTube: 10+ Tbps global bandwidth
Akamai: 200+ Tbps network capacity
Cloudflare: 100+ Tbps network capacity
Amazon CloudFront: 150+ Tbps capacity
```

#### Social Media Platforms
```
Facebook: 5+ Tbps global bandwidth
Instagram: 2+ Tbps (image/video heavy)
Twitter: 1+ Tbps (text/media mix)
TikTok: 8+ Tbps (short video focus)
```

#### Cloud Providers
```
AWS: 100+ Tbps inter-region capacity
Google Cloud: 50+ Tbps global network
Microsoft Azure: 60+ Tbps backbone
```

### Bandwidth by Service Type

#### Video Streaming Requirements
```
Netflix (per user):
- SD: 3 Mbps
- HD: 5 Mbps
- 4K: 25 Mbps

YouTube (per user):
- 480p: 1 Mbps
- 720p: 2.5 Mbps
- 1080p: 5 Mbps
- 4K: 20 Mbps
```

#### Gaming Bandwidth
```
Online gaming: 1-3 Mbps per player
Game downloads: 50-100 GB (burst bandwidth)
Game streaming: 10-35 Mbps per stream
Cloud gaming: 15-50 Mbps per session
```

---

## Bandwidth Optimization Strategies

### Content Optimization

#### Compression Techniques
```
Text compression (gzip): 70-90% size reduction
Image compression (WebP): 25-50% size reduction
Video compression (H.265): 50% size reduction vs H.264
Audio compression (AAC): 30-50% size reduction vs MP3
```

#### Content Delivery Optimization
```
CDN edge caching: 80-95% bandwidth reduction at origin
Image optimization: Responsive images, lazy loading
Video optimization: Adaptive bitrate streaming
Progressive loading: Critical content first
```

### Network Optimization

#### Protocol Optimization
```
HTTP/2: Multiplexing, header compression
HTTP/3 (QUIC): Reduced connection overhead
TCP optimization: Window scaling, congestion control
UDP optimization: For real-time applications
```

#### Caching Strategies
```
Browser caching: Reduce repeat requests
CDN caching: Serve content from edge locations
Application caching: Reduce backend load
Database caching: Minimize data transfer
```

### Infrastructure Optimization

#### Network Architecture
```
Multi-CDN: Distribute load across providers
Anycast: Route to nearest server
Load balancing: Distribute traffic efficiently
Peering agreements: Direct connections between networks
```

#### Bandwidth Management
```
Traffic shaping: Prioritize critical traffic
Quality of Service (QoS): Guarantee bandwidth for services
Rate limiting: Prevent bandwidth abuse
Burst allowance: Handle traffic spikes
```

---

## Bandwidth Planning and Capacity

### Capacity Planning Process

#### Traffic Analysis
```
1. Measure current bandwidth usage
2. Identify peak usage patterns
3. Analyze growth trends
4. Factor in seasonal variations
5. Plan for marketing campaigns/events
```

#### Growth Projections
```
Linear growth: Steady increase over time
Exponential growth: Rapid user acquisition
Seasonal patterns: Holiday traffic spikes
Event-driven: Product launches, viral content
```

### Bandwidth Provisioning

#### Overprovisioning Strategy
```
Base capacity: Average usage
Peak capacity: 3-5x average
Burst capacity: 10x average (short term)
Safety margin: 2x peak capacity
```

#### Cost Optimization
```
Reserved bandwidth: Lower cost for predictable usage
Burstable billing: Pay for actual usage spikes
Multi-provider: Negotiate better rates
Regional optimization: Cheaper bandwidth in some regions
```

---

## Interview Scenarios

### Scenario 1: Video Streaming Platform
**Question**: "Design bandwidth requirements for a video streaming platform with 10 million users."

**Answer Framework**:
```
1. User Behavior Analysis:
   - Peak concurrent users: 2 million (20%)
   - Average viewing session: 45 minutes
   - Video quality distribution:
     * SD (480p): 40% of streams, 1 Mbps
     * HD (720p): 45% of streams, 3 Mbps
     * 4K: 15% of streams, 15 Mbps

2. Bandwidth Calculation:
   - SD streams: 800,000 × 1 Mbps = 800 Gbps
   - HD streams: 900,000 × 3 Mbps = 2.7 Tbps
   - 4K streams: 300,000 × 15 Mbps = 4.5 Tbps
   - Total peak: 8 Tbps

3. Infrastructure Design:
   - CDN with 95% cache hit rate
   - Origin bandwidth: 8 Tbps × 0.05 = 400 Gbps
   - Global CDN capacity: 10 Tbps (25% safety margin)
   - Regional distribution across 20 locations

4. Optimization:
   - Adaptive bitrate streaming
   - Content pre-positioning
   - Compression optimization
   - Multi-CDN strategy
```

### Scenario 2: Social Media Platform
**Question**: "Calculate bandwidth needs for a social media platform like Instagram."

**Answer Framework**:
```
1. Content Analysis:
   - 500 million daily active users
   - Average 20 photos viewed per user per day
   - Average photo size: 200 KB
   - Peak concurrent users: 50 million

2. Bandwidth Calculation:
   - Daily photo views: 500M × 20 = 10 billion
   - Peak hour traffic: 10B / 24 × 3 = 1.25 billion photos/hour
   - Peak QPS: 1.25B / 3600 = 347,000 photos/second
   - Bandwidth: 347,000 × 200 KB × 8 = 556 Gbps

3. Additional Considerations:
   - Video content: 30% of posts, 2 MB average
   - Stories: 100 million daily, 500 KB average
   - Live streaming: 1% of users, 3 Mbps each
   - Total peak bandwidth: ~2 Tbps

4. Optimization Strategy:
   - Image compression and WebP format
   - CDN with 98% cache hit rate
   - Progressive image loading
   - Regional content distribution
```

### Scenario 3: Enterprise Video Conferencing
**Question**: "Design bandwidth requirements for enterprise video conferencing supporting 100,000 concurrent meetings."

**Answer Framework**:
```
1. Meeting Characteristics:
   - Average meeting size: 8 participants
   - Total participants: 800,000 concurrent
   - Video quality: 720p HD
   - Audio quality: 64 kbps

2. Bandwidth per Participant:
   - Upload: 1.5 Mbps (own video) + 64 kbps (audio)
   - Download: 1.5 Mbps × 7 others + 64 kbps × 7
   - Total per participant: 12 Mbps

3. Total Bandwidth Calculation:
   - 800,000 participants × 12 Mbps = 9.6 Tbps
   - With compression (30% reduction): 6.7 Tbps
   - Infrastructure overhead (20%): 8 Tbps

4. Architecture Design:
   - Regional media servers
   - Selective forwarding units (SFUs)
   - Adaptive bitrate based on network conditions
   - Fallback to audio-only for poor connections
```

---

## Bandwidth Monitoring and Management

### Key Metrics to Monitor

#### Network Utilization
```
• Bandwidth utilization percentage
• Peak vs average usage patterns
• Upload vs download ratios
• Regional traffic distribution
```

#### Performance Metrics
```
• Throughput achieved vs available bandwidth
• Packet loss rates
• Jitter and latency measurements
• Quality of service metrics
```

### Bandwidth Management Tools

#### Traffic Analysis
```
• Network monitoring tools (SNMP, NetFlow)
• Application performance monitoring
• CDN analytics and reporting
• Real-time traffic dashboards
```

#### Optimization Tools
```
• Content delivery networks
• Traffic shaping appliances
• Compression gateways
• Caching solutions
```

---

## Practice Problems

> **Learn by Doing:** Work through these problems to master bandwidth calculations and optimization.

### Problem 1: E-commerce Platform Bandwidth

**Question**: "Calculate bandwidth requirements for an e-commerce platform during Black Friday with 10x normal traffic."

**Your Task**: Design bandwidth capacity for peak shopping event.

**Hints**:
- Consider `product images`, `user sessions`, and `checkout flows`
- Think about `CDN optimization` and `caching strategies`
- Plan for `geographic distribution` and `failover`

**Solution**:
```
1. Normal Traffic Analysis:
   - 1 million daily active users
   - 50 page views per user per day
   - Average page size: 2 MB (images, CSS, JS)
   - Normal peak: 100,000 concurrent users

2. Black Friday Projections:
   - 10x traffic: 1 million concurrent users
   - Higher engagement: 100 page views per user
   - Larger product images: 3 MB average page size
   - Peak duration: 4 hours

3. Bandwidth Calculation:
   - Page views per second: 1M users × 100 views / 14,400s = 6,944 PPS
   - Bandwidth: 6,944 × 3 MB × 8 = 167 Gbps
   - With 95% CDN cache hit rate: 8.3 Gbps origin bandwidth

4. Infrastructure Design:
   - CDN capacity: 200 Gbps (20% safety margin)
   - Origin servers: 15 Gbps capacity
   - Multi-CDN setup for redundancy
   - Pre-warming popular product pages
   - Image optimization (WebP, responsive images)

5. Monitoring:
   - Real-time bandwidth utilization
   - CDN cache hit rates
   - Origin server load
   - User experience metrics (page load times)
```

---

### Problem 2: Live Streaming Event Bandwidth

**Question**: "Design bandwidth infrastructure for a live streaming event expecting 5 million concurrent viewers."

**Your Task**: Plan global streaming infrastructure with quality adaptation.

**Hints**:
- Consider `multiple quality levels` and `adaptive streaming`
- Think about `global distribution` and `edge servers`
- Plan for `redundancy` and `failover scenarios`

**Solution**:
```
1. Viewer Distribution Analysis:
   - 5 million concurrent viewers globally
   - Quality preferences:
     * 480p: 30% (1.5M viewers, 1 Mbps each)
     * 720p: 50% (2.5M viewers, 3 Mbps each)
     * 1080p: 20% (1M viewers, 6 Mbps each)

2. Bandwidth Calculation:
   - 480p streams: 1.5M × 1 Mbps = 1.5 Tbps
   - 720p streams: 2.5M × 3 Mbps = 7.5 Tbps
   - 1080p streams: 1M × 6 Mbps = 6 Tbps
   - Total: 15 Tbps

3. Global Infrastructure:
   - 50 edge locations worldwide
   - Average 300 Gbps per edge location
   - 3 origin servers with 2 Tbps capacity each
   - Multi-CDN deployment for redundancy

4. Optimization Strategy:
   - Adaptive bitrate streaming (ABR)
   - Content pre-positioning at edge
   - Real-time quality adjustment based on network
   - Fallback to lower quality during congestion

5. Redundancy Planning:
   - 2x capacity provisioning
   - Automatic failover between CDNs
   - Multiple origin servers
   - Real-time traffic load balancing
```

---

### Problem 3: Cloud Storage Bandwidth Planning

**Question**: "Design bandwidth requirements for a cloud storage service with 100 million users backing up photos and videos."

**Your Task**: Calculate upload/download bandwidth needs with usage patterns.

**Hints**:
- Consider `upload vs download` patterns
- Think about `peak usage times` and `sync behavior`
- Plan for `different file types` and `compression`

**Solution**:
```
1. User Behavior Analysis:
   - 100 million total users
   - 20% active daily (20 million users)
   - Average uploads: 50 photos + 5 videos per day
   - Photo size: 3 MB, Video size: 50 MB
   - Peak usage: 8 PM local time (staggered globally)

2. Upload Bandwidth Calculation:
   - Daily photos: 20M × 50 = 1 billion photos
   - Daily videos: 20M × 5 = 100 million videos
   - Photo data: 1B × 3 MB = 3 PB/day
   - Video data: 100M × 50 MB = 5 PB/day
   - Total: 8 PB/day

3. Peak Hour Analysis:
   - Peak traffic: 20% of daily uploads in 2 hours
   - Peak data: 8 PB × 0.2 / 2 hours = 800 TB/hour
   - Peak bandwidth: 800 TB/hour = 1.78 Tbps

4. Download Patterns:
   - Download/upload ratio: 3:1
   - Peak download bandwidth: 5.3 Tbps
   - Total peak bandwidth: 7.1 Tbps

5. Infrastructure Design:
   - Global upload endpoints (20 regions)
   - Regional bandwidth: 400 Gbps average
   - Compression: 30% reduction for photos, 10% for videos
   - Deduplication: 20% storage savings
   - CDN for frequently accessed content

6. Optimization:
   - Delta sync (only changed portions)
   - Background uploads during off-peak
   - Compression and deduplication
   - Tiered storage (hot/warm/cold)
```

---

## Related Topics for Deep Dive
- Capacity Planning & Back-of-the-Envelope Estimation
- Horizontal vs Vertical Scaling
- Latency & Percentiles (P50, P95, P99)
- Performance Metrics
- Throughput Optimization
- Response Time Optimization
- Fault Tolerance and Reliability
- Load Balancing Strategies
- Caching Architectures
- CDN Optimization

---

## References

> **Deep Dive Resources:** Essential reading for mastering bandwidth planning and optimization.

### Network Fundamentals
| Resource | Description |
|----------|-------------|
| [High Performance Browser Networking](https://hpbn.co/) | Network performance fundamentals |
| [Computer Networks by Tanenbaum](https://www.pearson.com/store/p/computer-networks/P100000648863) | Comprehensive networking concepts |
| [TCP/IP Illustrated](https://www.informit.com/series/series_detail.aspx?ser=2065513) | Deep dive into network protocols |

### CDN and Content Delivery
| Resource | Description |
|----------|-------------|
| [Cloudflare Learning Center](https://www.cloudflare.com/learning/) | CDN and bandwidth optimization |
| [Akamai Technical Documentation](https://techdocs.akamai.com/) | Content delivery best practices |
| [AWS CloudFront Documentation](https://docs.aws.amazon.com/cloudfront/) | Cloud CDN implementation |

### Performance Optimization
| Resource | Description |
|----------|-------------|
| [Web Performance Optimization](https://developers.google.com/web/fundamentals/performance) | Google's performance guidelines |
| [Video Streaming Optimization](https://bitmovin.com/video-streaming/) | Video bandwidth optimization |
| [Network Performance Monitoring](https://www.solarwinds.com/network-performance-monitor) | Bandwidth monitoring tools |

---