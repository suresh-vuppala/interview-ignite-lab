import os
import json

# Complete lesson definitions for existing files
lessons = {
    "load-balancing": {
        "load-balancing-essentials": {
            "intro-load-balancing": {
                "title": "Introduction to Load Balancing",
                "questions": [
                    "Design load balancing strategy for a web application with 1M users",
                    "Compare Layer 4 vs Layer 7 load balancing for different use cases",
                    "How would you handle session affinity in a load-balanced environment?",
                    "Design load balancer failover and health checking mechanisms"
                ]
            },
            "load-balancing-algorithms": {
                "title": "Load Balancing Algorithms",
                "questions": [
                    "Choose appropriate load balancing algorithm for different scenarios",
                    "Design weighted round-robin for servers with different capacities",
                    "How would you implement least connections algorithm at scale?",
                    "Design consistent hashing for distributed cache load balancing"
                ]
            },
            "round-robin": {
                "title": "Round Robin Load Balancing",
                "questions": [
                    "Implement round-robin algorithm for microservices load balancing",
                    "How would you handle server failures in round-robin distribution?",
                    "Design weighted round-robin for heterogeneous server capacities",
                    "Optimize round-robin performance for high-throughput systems"
                ]
            },
            "least-connections": {
                "title": "Least Connections Algorithm",
                "questions": [
                    "Implement least connections algorithm for database connection pooling",
                    "How would you track active connections across distributed load balancers?",
                    "Design least connections with server capacity weighting",
                    "Handle connection counting in stateless load balancer environments"
                ]
            },
            "consistent-hashing": {
                "title": "Consistent Hashing for Load Balancing",
                "questions": [
                    "Design consistent hashing for distributed cache load balancing",
                    "How would you handle node additions/removals in consistent hashing?",
                    "Implement virtual nodes to improve load distribution",
                    "Design consistent hashing for session affinity requirements"
                ]
            },
            "types-load-balancers": {
                "title": "Types of Load Balancers",
                "questions": [
                    "Compare hardware vs software load balancers for enterprise deployment",
                    "Design Layer 4 vs Layer 7 load balancing for different protocols",
                    "How would you choose between DNS, network, and application load balancing?",
                    "Implement hybrid load balancing with multiple load balancer types"
                ]
            },
            "stateless-vs-stateful-load-balancers": {
                "title": "Stateless vs Stateful Load Balancers",
                "questions": [
                    "Design stateless load balancer for high availability requirements",
                    "How would you handle session persistence in stateless load balancers?",
                    "Compare stateful vs stateless load balancers for different use cases",
                    "Implement load balancer state synchronization across multiple instances"
                ]
            },
            "load-balancer-vs-api-gateway": {
                "title": "Load Balancer vs API Gateway",
                "questions": [
                    "Compare load balancer and API gateway for microservices architecture",
                    "When would you use both load balancer and API gateway together?",
                    "Design traffic routing with load balancer and API gateway combination",
                    "Implement service discovery with load balancer vs API gateway approaches"
                ]
            }
        }
    },
    "caching": {
        "caching-fundamentals": {
            "caching-basics": {
                "title": "Caching Fundamentals",
                "questions": [
                    "Design multi-level caching strategy for e-commerce platform",
                    "How would you determine what data to cache and cache TTL values?",
                    "Design cache invalidation strategy for frequently changing data",
                    "Implement caching for read-heavy vs write-heavy workloads"
                ]
            },
            "why-caching-matters": {
                "title": "Why Caching Matters",
                "questions": [
                    "Analyze performance impact of caching for database-heavy applications",
                    "How would you measure ROI of implementing caching infrastructure?",
                    "Design caching strategy to reduce API response times by 80%",
                    "Calculate cost savings from reduced database load through caching"
                ]
            },
            "hot-vs-cold-data": {
                "title": "Hot vs Cold Data",
                "questions": [
                    "Design data classification strategy for optimal caching",
                    "How would you identify hot data patterns in user behavior analytics?",
                    "Implement automatic hot/cold data migration in cache systems",
                    "Design cache warming strategies for predictable hot data patterns"
                ]
            },
            "cache-hierarchies": {
                "title": "Cache Hierarchies",
                "questions": [
                    "Design multi-tier cache hierarchy for global application",
                    "How would you implement cache coherence across hierarchy levels?",
                    "Design cache hierarchy with different eviction policies per level",
                    "Optimize cache hierarchy for mobile app with offline capabilities"
                ]
            },
            "cache-performance-metrics": {
                "title": "Cache Performance Metrics",
                "questions": [
                    "Design comprehensive cache monitoring and alerting system",
                    "How would you optimize cache hit ratio for cost-performance balance?",
                    "Implement cache performance analytics for capacity planning",
                    "Design cache metrics dashboard for operational visibility"
                ]
            }
        },
        "caching-patterns-strategies": {
            "cache-patterns-overview": {
                "title": "Cache Patterns Overview",
                "questions": [
                    "Compare different caching patterns for various application types",
                    "How would you choose appropriate cache pattern for financial systems?",
                    "Design hybrid caching approach combining multiple patterns",
                    "Implement pattern selection based on data access characteristics"
                ]
            },
            "cache-aside": {
                "title": "Cache-Aside Pattern",
                "questions": [
                    "Implement cache-aside pattern for user profile data",
                    "How would you handle cache-aside with database transactions?",
                    "Design cache-aside with eventual consistency considerations",
                    "Implement cache-aside pattern with error handling and fallbacks"
                ]
            },
            "write-through": {
                "title": "Write-Through Cache",
                "questions": [
                    "Design write-through caching for financial transaction system",
                    "How would you handle write-through cache failures and rollbacks?",
                    "Implement write-through cache with strong consistency requirements",
                    "Design write-through cache performance optimization strategies"
                ]
            },
            "write-back": {
                "title": "Write-Back Cache",
                "questions": [
                    "Implement write-back caching for high-write workloads",
                    "How would you handle data loss risks in write-back caching?",
                    "Design write-back cache with batch processing optimization",
                    "Implement write-back cache with conflict resolution strategies"
                ]
            },
            "read-through-refresh-ahead": {
                "title": "Read-Through and Refresh-Ahead",
                "questions": [
                    "Design read-through cache for microservices data access",
                    "How would you implement refresh-ahead for predictable access patterns?",
                    "Design read-through cache with fallback to multiple data sources",
                    "Implement refresh-ahead with machine learning prediction models"
                ]
            },
            "cache-invalidation-strategies": {
                "title": "Cache Invalidation Strategies",
                "questions": [
                    "Design cache invalidation for real-time inventory management",
                    "How would you implement distributed cache invalidation?",
                    "Design cache invalidation with event-driven architecture",
                    "Implement cache invalidation with minimal performance impact"
                ]
            },
            "caching-consistency-challenges": {
                "title": "Caching Consistency Challenges",
                "questions": [
                    "Handle cache consistency in distributed microservices architecture",
                    "How would you resolve cache consistency conflicts in multi-region setup?",
                    "Design eventual consistency model for distributed caching",
                    "Implement strong consistency guarantees for critical cached data"
                ]
            }
        },
        "cache-management-scaling": {
            "cache-eviction-policies": {
                "title": "Cache Eviction Policies",
                "questions": [
                    "Choose appropriate cache eviction policy for different use cases",
                    "Design LRU cache implementation for memory-constrained environment",
                    "How would you implement custom eviction policies for business logic?",
                    "Design cache eviction with priority-based and time-based policies"
                ]
            },
            "cache-ttl-expiry": {
                "title": "Cache TTL and Expiry",
                "questions": [
                    "Design optimal TTL strategy for different data types",
                    "How would you implement dynamic TTL based on data access patterns?",
                    "Design cache expiry with graceful degradation mechanisms",
                    "Implement TTL optimization for cost and performance balance"
                ]
            },
            "distributed-caching-consistent-hashing": {
                "title": "Distributed Caching with Consistent Hashing",
                "questions": [
                    "Design distributed cache with consistent hashing for scalability",
                    "How would you handle cache node failures in consistent hashing?",
                    "Implement virtual nodes for better load distribution in cache cluster",
                    "Design consistent hashing with replication for high availability"
                ]
            },
            "scaling-cache-redis-memcached": {
                "title": "Scaling Cache with Redis and Memcached",
                "questions": [
                    "Design Redis cluster for high-availability caching",
                    "How would you choose between Redis and Memcached for different scenarios?",
                    "Implement Redis Sentinel for automatic failover",
                    "Design Memcached scaling strategy for memory-intensive workloads"
                ]
            },
            "cache-stampede-dogpile": {
                "title": "Cache Stampede and Dogpile Effect",
                "questions": [
                    "Prevent cache stampede in high-traffic e-commerce applications",
                    "How would you implement cache warming to avoid dogpile effects?",
                    "Design cache refresh strategies to minimize stampede impact",
                    "Implement distributed locking to prevent concurrent cache rebuilds"
                ]
            },
            "thundering-herd-mitigation": {
                "title": "Thundering Herd Mitigation",
                "questions": [
                    "Design thundering herd mitigation for cache expiry scenarios",
                    "How would you implement jittered cache expiry to reduce herd effects?",
                    "Design cache refresh queuing to prevent thundering herd",
                    "Implement probabilistic cache refresh for herd mitigation"
                ]
            },
            "cache-write-coalescing": {
                "title": "Cache Write Coalescing",
                "questions": [
                    "Implement write coalescing for high-frequency cache updates",
                    "How would you design batch write operations for cache efficiency?",
                    "Design write coalescing with consistency guarantees",
                    "Implement write coalescing for distributed cache systems"
                ]
            }
        }
    },
    "cdn": {
        "cdn-fundamentals": {
            "what-is-cdn": {
                "title": "What is CDN",
                "questions": [
                    "Design CDN architecture for global video streaming platform",
                    "How would you choose CDN edge locations for optimal performance?",
                    "Design CDN strategy for static vs dynamic content delivery",
                    "Implement CDN with origin server failover and redundancy"
                ]
            },
            "how-cdn-works": {
                "title": "How CDN Works",
                "questions": [
                    "Explain CDN request routing and content delivery process",
                    "How would you optimize CDN cache hit ratios for different content types?",
                    "Design CDN with intelligent request routing based on user location",
                    "Implement CDN with real-time performance monitoring and optimization"
                ]
            },
            "cdn-benefits": {
                "title": "CDN Benefits",
                "questions": [
                    "Analyze CDN ROI for different types of web applications",
                    "How would you measure CDN performance improvements?",
                    "Design CDN strategy for mobile app content delivery",
                    "Implement CDN for API acceleration and global distribution"
                ]
            }
        },
        "cdn-architecture-components": {
            "edge-caching-request-routing": {
                "title": "Edge Caching and Request Routing",
                "questions": [
                    "Design intelligent request routing for global CDN network",
                    "How would you implement edge caching with dynamic content support?",
                    "Design request routing with real-time performance optimization",
                    "Implement edge caching with personalized content delivery"
                ]
            },
            "cdn-cache-hierarchies": {
                "title": "CDN Cache Hierarchies",
                "questions": [
                    "Design multi-tier CDN cache hierarchy for optimal performance",
                    "How would you implement cache coherence across CDN hierarchy?",
                    "Design CDN hierarchy with regional and global cache layers",
                    "Implement CDN cache hierarchy with intelligent content placement"
                ]
            },
            "cdn-static-vs-dynamic": {
                "title": "CDN Static vs Dynamic Content",
                "questions": [
                    "Design CDN strategy for mixed static and dynamic content",
                    "How would you implement dynamic content caching at CDN edge?",
                    "Design CDN with edge computing for dynamic content generation",
                    "Implement CDN optimization for API responses and dynamic data"
                ]
            },
            "cdn-geo-replication": {
                "title": "CDN Geographic Replication",
                "questions": [
                    "Design CDN geo-replication strategy for global content distribution",
                    "How would you implement content synchronization across CDN regions?",
                    "Design CDN with regional compliance and data residency requirements",
                    "Implement CDN geo-replication with conflict resolution mechanisms"
                ]
            }
        }
    }
}

def generate_lesson_content(title, questions):
    return f"""## Interview Focus

**Critical Interview Questions:**
- "{questions[0]}"
- "{questions[1]}"
- "{questions[2]}"
- "{questions[3]}"

---

## Why {title} Matters

### In Technical Interviews
> **Key Point:** Understanding {title.lower()} is essential for designing scalable, performant, and reliable distributed systems.

- **Demonstrates system design expertise** - critical for senior roles
- **Shows practical implementation knowledge** - real-world experience
- **Proves architectural thinking** - design trade-offs and decisions
- **Foundation for scalability** - handles growth and performance

### In Real Systems
> **Important:** Proper {title.lower()} implementation ensures system performance, reliability, and user experience.

- **Performance optimization** - reduce latency and improve throughput
- **Scalability enablement** - handle growing traffic and users
- **Reliability assurance** - ensure high availability and fault tolerance
- **Cost optimization** - efficient resource utilization

---

## Core Concepts

> **Critical:** Master these fundamental concepts for interview success.

### Key Principles

```
Fundamental Concepts:
- Design patterns and best practices
- Performance and scalability considerations
- Security and reliability requirements
- Implementation trade-offs
- Monitoring and optimization
```

### Architecture Patterns

```
Common Patterns:
- Scalable design approaches
- High availability strategies
- Performance optimization techniques
- Security implementation patterns
- Operational best practices
```

---

## Interview Examples

### Example 1: Design Challenge

**Question**: "Design a system that effectively implements {title.lower()}."

> **Key Insight:** Break down requirements and explain architectural decisions.

**Solution**:
```
1. Requirements Analysis:
   - Functional requirements
   - Non-functional requirements (performance, scalability)
   - Constraints and assumptions
   - Success metrics

2. Architecture Design:
   - High-level architecture
   - Component breakdown
   - Data flow and interactions
   - Technology choices

3. Implementation Strategy:
   - Detailed design decisions
   - Performance considerations
   - Security measures
   - Monitoring and alerting

4. Scalability Planning:
   - Growth projections
   - Scaling strategies
   - Bottleneck identification
   - Optimization opportunities
```

### Example 2: Optimization Problem

**Question**: "How would you optimize an existing system using {title.lower()}?"

> **Important:** Focus on measurable improvements and trade-offs.

**Solution**:
```
1. Current State Analysis:
   - Performance baseline
   - Bottleneck identification
   - Resource utilization
   - User experience metrics

2. Optimization Strategy:
   - Quick wins and low-hanging fruit
   - Long-term improvements
   - Technology upgrades
   - Process optimizations

3. Implementation Plan:
   - Phased rollout approach
   - Risk mitigation strategies
   - Testing and validation
   - Rollback procedures

4. Success Measurement:
   - Key performance indicators
   - Before/after comparisons
   - Business impact metrics
   - Continuous monitoring
```

---

## Best Practices

### Do's
> **Success Patterns:** Follow these guidelines for robust implementations.

- **Design for `scalability`** - plan for growth from the beginning
- **Implement `monitoring`** - track performance and health metrics
- **Ensure `security`** - implement proper access controls and encryption
- **Plan for `failures`** - design fault-tolerant and resilient systems
- **Optimize `performance`** - minimize latency and maximize throughput
- **Document `thoroughly`** - maintain clear documentation and runbooks

### Don'ts
> **Common Pitfalls:** Avoid these mistakes in production systems.

- **Don't ignore `performance`** - always consider performance implications
- **Don't skip `testing`** - thoroughly test under realistic conditions
- **Don't over-engineer** - keep solutions simple and maintainable
- **Don't forget `security`** - implement security throughout the design
- **Don't neglect `monitoring`** - ensure proper observability
- **Don't ignore `costs`** - consider operational and infrastructure costs

---

## Practice Problems

> **Learn by Doing:** Apply concepts to real-world scenarios.

### Problem 1: System Design Challenge

**Question**: Design a comprehensive system that leverages {title.lower()} effectively.

**Your Task**: Create a scalable architecture with proper implementation.

**Hints**:
- Consider `performance` requirements
- Think about `scalability` needs
- Plan for `reliability` and fault tolerance
- Address `security` concerns

**Solution**:
```
1. Architecture Overview:
   - System components and interactions
   - Data flow and processing pipeline
   - Technology stack selection
   - Deployment architecture

2. Detailed Design:
   - Component specifications
   - Interface definitions
   - Data models and schemas
   - Security implementation

3. Scalability Strategy:
   - Horizontal scaling approach
   - Load distribution mechanisms
   - Performance optimization
   - Capacity planning

4. Operational Considerations:
   - Monitoring and alerting
   - Deployment strategies
   - Disaster recovery
   - Maintenance procedures
```

---

### Problem 2: Performance Optimization

**Question**: Optimize an existing system's performance using {title.lower()} principles.

**Your Task**: Identify bottlenecks and implement improvements.

**Hints**:
- Analyze `current performance`
- Identify `optimization opportunities`
- Consider `implementation complexity`
- Measure `improvement impact`

**Solution**:
```
1. Performance Analysis:
   - Baseline measurements
   - Bottleneck identification
   - Resource utilization analysis
   - User experience assessment

2. Optimization Strategy:
   - Priority-based improvements
   - Technology enhancements
   - Architecture modifications
   - Process optimizations

3. Implementation Approach:
   - Incremental improvements
   - A/B testing methodology
   - Risk management
   - Performance validation

4. Results Measurement:
   - Performance metrics
   - Business impact
   - Cost implications
   - User satisfaction
```

---

## References and Further Reading

### Essential Resources
| Resource | Description |
|----------|-------------|
| [System Design Primer](https://github.com/donnemartin/system-design-primer) | Comprehensive system design guide |
| [High Scalability](http://highscalability.com/) | Real-world architecture case studies |
| [AWS Architecture Center](https://aws.amazon.com/architecture/) | Cloud architecture patterns |

### Industry Case Studies
| Company | Resource | Focus |
|---------|----------|-------|
| Netflix | [Tech Blog](https://netflixtechblog.com/) | Scalable architecture patterns |
| Uber | [Engineering Blog](https://eng.uber.com/) | High-performance systems |
| Airbnb | [Engineering Blog](https://medium.com/airbnb-engineering) | Scalability and reliability |

### Tools and Technologies
| Tool | Description |
|------|-------------|
| [Monitoring Tools](https://prometheus.io/) | System monitoring and alerting |
| [Load Testing](https://k6.io/) | Performance testing and validation |
| [Documentation](https://www.gitbook.com/) | Technical documentation platforms |

---

## Deep Dive Topics

### Advanced Concepts
- **Performance Engineering** - Advanced optimization techniques and methodologies
- **Reliability Engineering** - Building fault-tolerant and resilient systems
- **Security Architecture** - Implementing comprehensive security measures

### Related Topics for Deep Dive

- **[Performance Metrics](../system-design-foundations/scaling-performance-basics/performance-metrics)** - Monitor system performance
- **[Networking](../networking-proxy/networking-fundamentals/network-overview)** - Understand network fundamentals
- **[Database Design](../databases-storage-design/intro-database/database-fundamentals)** - Design scalable data storage
- **[Microservices](../system-design-foundations/architecture-fundamentals/monolithic-vs-microservices)** - Distributed system architecture
"""

def update_json_file(json_path):
    with open(json_path, 'r') as f:
        data = json.load(f)
    
    data['isPosted'] = True
    
    with open(json_path, 'w') as f:
        json.dump(data, f, indent=2)

# Generate content for all lessons
base_path = r"d:\interview-ignite-lab\src\data\courses\system-design"
total_lessons = 0

for module_name, categories in lessons.items():
    print(f"\nProcessing module: {module_name}")
    
    for category, category_lessons in categories.items():
        print(f"  Processing category: {category}")
        
        for slug, lesson_data in category_lessons.items():
            lesson_path = os.path.join(base_path, module_name, category, slug)
            md_file = os.path.join(lesson_path, f"{slug}.md")
            json_file = os.path.join(lesson_path, f"{slug}.json")
            
            # Check if files exist
            if os.path.exists(json_file) and os.path.exists(lesson_path):
                # Generate and write markdown content
                content = generate_lesson_content(lesson_data['title'], lesson_data['questions'])
                with open(md_file, 'w', encoding='utf-8') as f:
                    f.write(content)
                
                # Update JSON to mark as posted
                update_json_file(json_file)
                
                print(f"    Generated: {lesson_data['title']}")
                total_lessons += 1
            else:
                print(f"    Skipped: {lesson_data['title']} (files not found)")

print(f"\nSuccessfully generated content for {total_lessons} lessons across {len(lessons)} modules!")