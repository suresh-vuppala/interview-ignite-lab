import os
import json

# Module definitions with all lessons
modules = {
    "api-layer": {
        "api-design-communication": {
            "introduction-to-apis": {
                "title": "Introduction to APIs",
                "questions": [
                    "Design a RESTful API for a social media platform with 10M users",
                    "Explain API design principles for microservices architecture",
                    "How would you version APIs without breaking existing clients?",
                    "Design API authentication and authorization for enterprise applications"
                ]
            },
            "sync-vs-async-apis": {
                "title": "Synchronous vs Asynchronous APIs",
                "questions": [
                    "When would you choose async APIs over sync APIs for order processing?",
                    "Design async API architecture for a payment processing system",
                    "How would you handle callback failures in async API design?",
                    "Implement request-response correlation for async operations"
                ]
            },
            "convert-sync-to-async-apis": {
                "title": "Converting Sync to Async APIs",
                "questions": [
                    "Migrate a synchronous file processing API to asynchronous",
                    "Design backward compatibility during sync-to-async migration",
                    "How would you handle client polling vs webhooks for async results?",
                    "Implement status tracking for long-running async operations"
                ]
            },
            "api-idempotent": {
                "title": "API Idempotency",
                "questions": [
                    "Design idempotent payment processing APIs",
                    "How would you implement idempotency keys for REST APIs?",
                    "Handle duplicate requests in a distributed system",
                    "Design idempotent APIs for inventory management system"
                ]
            }
        },
        "api-authentication-methods": {
            "basic-auth": {
                "title": "Basic Authentication",
                "questions": [
                    "When is Basic Auth appropriate vs other authentication methods?",
                    "Implement secure Basic Auth for internal APIs",
                    "How would you migrate from Basic Auth to token-based auth?",
                    "Design Basic Auth with proper security headers and HTTPS"
                ]
            },
            "token-auth": {
                "title": "Token-Based Authentication",
                "questions": [
                    "Design token-based auth for a mobile application",
                    "How would you handle token refresh and expiration?",
                    "Implement secure token storage and transmission",
                    "Design token revocation for compromised accounts"
                ]
            },
            "jwt-auth": {
                "title": "JWT Authentication",
                "questions": [
                    "Design JWT-based authentication for microservices",
                    "How would you handle JWT token size and performance?",
                    "Implement JWT refresh token rotation strategy",
                    "Design stateless authentication with JWT for 1M users"
                ]
            },
            "oauth2": {
                "title": "OAuth 2.0",
                "questions": [
                    "Design OAuth 2.0 flow for third-party integrations",
                    "Implement OAuth 2.0 authorization server for enterprise",
                    "How would you handle OAuth scope management and permissions?",
                    "Design OAuth 2.0 for mobile app with PKCE"
                ]
            }
        },
        "api-gateways": {
            "api-gateway-role-importance": {
                "title": "API Gateway Role and Importance",
                "questions": [
                    "Design API gateway architecture for 100 microservices",
                    "How would you implement rate limiting and throttling in API gateway?",
                    "Design API gateway for multi-tenant SaaS application",
                    "Implement API gateway with service discovery and load balancing"
                ]
            },
            "aws-api-gateway": {
                "title": "AWS API Gateway",
                "questions": [
                    "Design serverless API architecture using AWS API Gateway",
                    "How would you implement custom authorizers in AWS API Gateway?",
                    "Design API Gateway with Lambda integration for high throughput",
                    "Implement API Gateway caching and performance optimization"
                ]
            },
            "kong-gateway": {
                "title": "Kong API Gateway",
                "questions": [
                    "Design Kong gateway setup for microservices platform",
                    "How would you implement custom plugins in Kong?",
                    "Design Kong clustering for high availability",
                    "Implement Kong with service mesh integration"
                ]
            },
            "nginx-gateway": {
                "title": "NGINX as API Gateway",
                "questions": [
                    "Configure NGINX as API gateway for REST services",
                    "How would you implement rate limiting with NGINX Plus?",
                    "Design NGINX gateway with SSL termination and load balancing",
                    "Implement NGINX with dynamic upstream configuration"
                ]
            },
            "apigee-gateway": {
                "title": "Apigee API Gateway",
                "questions": [
                    "Design enterprise API management with Apigee",
                    "How would you implement API analytics and monitoring in Apigee?",
                    "Design Apigee policies for security and transformation",
                    "Implement Apigee hybrid deployment for on-premises integration"
                ]
            },
            "azure-api-management": {
                "title": "Azure API Management",
                "questions": [
                    "Design Azure API Management for enterprise applications",
                    "How would you implement developer portal with Azure APIM?",
                    "Design Azure APIM with multiple environments and versioning",
                    "Implement Azure APIM with Application Insights monitoring"
                ]
            }
        }
    },
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
            "hardware-vs-software-load-balancers": {
                "title": "Hardware vs Software Load Balancers",
                "questions": [
                    "Compare hardware and software load balancers for enterprise deployment",
                    "Design cost-effective load balancing solution for startup vs enterprise",
                    "How would you migrate from hardware to software load balancers?",
                    "Design hybrid load balancing with both hardware and software components"
                ]
            },
            "global-load-balancing": {
                "title": "Global Load Balancing",
                "questions": [
                    "Design global load balancing for multi-region application",
                    "How would you implement DNS-based global load balancing?",
                    "Design disaster recovery with global load balancer failover",
                    "Implement geolocation-based traffic routing for global users"
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
            "cache-hit-miss-ratio": {
                "title": "Cache Hit/Miss Ratio Optimization",
                "questions": [
                    "Optimize cache hit ratio for a content delivery system",
                    "How would you monitor and improve cache performance metrics?",
                    "Design cache warming strategies for predictable traffic patterns",
                    "Implement cache analytics and optimization for cost reduction"
                ]
            },
            "cache-eviction-policies": {
                "title": "Cache Eviction Policies",
                "questions": [
                    "Choose appropriate cache eviction policy for different use cases",
                    "Design LRU cache implementation for memory-constrained environment",
                    "How would you implement custom eviction policies for business logic?",
                    "Design cache eviction with priority-based and time-based policies"
                ]
            }
        },
        "caching-patterns-strategies": {
            "cache-aside-pattern": {
                "title": "Cache-Aside Pattern",
                "questions": [
                    "Implement cache-aside pattern for user profile data",
                    "How would you handle cache-aside with database transactions?",
                    "Design cache-aside with eventual consistency considerations",
                    "Implement cache-aside pattern with error handling and fallbacks"
                ]
            },
            "write-through-cache": {
                "title": "Write-Through Cache",
                "questions": [
                    "Design write-through caching for financial transaction system",
                    "How would you handle write-through cache failures and rollbacks?",
                    "Implement write-through cache with strong consistency requirements",
                    "Design write-through cache performance optimization strategies"
                ]
            },
            "write-behind-cache": {
                "title": "Write-Behind Cache",
                "questions": [
                    "Implement write-behind caching for high-write workloads",
                    "How would you handle data loss risks in write-behind caching?",
                    "Design write-behind cache with batch processing optimization",
                    "Implement write-behind cache with conflict resolution strategies"
                ]
            },
            "distributed-caching": {
                "title": "Distributed Caching",
                "questions": [
                    "Design distributed cache architecture for microservices",
                    "How would you handle cache consistency across multiple nodes?",
                    "Implement distributed cache with partitioning and replication",
                    "Design distributed cache failover and data recovery mechanisms"
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
            "cdn-benefits-use-cases": {
                "title": "CDN Benefits and Use Cases",
                "questions": [
                    "Analyze CDN ROI for different types of web applications",
                    "How would you measure CDN performance improvements?",
                    "Design CDN strategy for mobile app content delivery",
                    "Implement CDN for API acceleration and global distribution"
                ]
            },
            "cdn-vs-traditional-hosting": {
                "title": "CDN vs Traditional Hosting",
                "questions": [
                    "Compare CDN vs traditional hosting for different scenarios",
                    "How would you migrate from traditional hosting to CDN?",
                    "Design hybrid approach combining CDN and traditional hosting",
                    "Analyze cost-benefit of CDN vs scaling traditional infrastructure"
                ]
            }
        },
        "cdn-architecture-components": {
            "edge-servers-pop": {
                "title": "Edge Servers and Points of Presence",
                "questions": [
                    "Design edge server placement strategy for global coverage",
                    "How would you optimize edge server capacity and caching?",
                    "Design edge server failover and load balancing mechanisms",
                    "Implement edge computing capabilities at CDN edge servers"
                ]
            },
            "origin-servers": {
                "title": "Origin Servers",
                "questions": [
                    "Design origin server architecture for CDN integration",
                    "How would you handle origin server scaling and redundancy?",
                    "Design origin server caching and content optimization",
                    "Implement origin server monitoring and health checking"
                ]
            },
            "cdn-caching-strategies": {
                "title": "CDN Caching Strategies",
                "questions": [
                    "Design CDN caching strategy for different content types",
                    "How would you implement cache invalidation across CDN network?",
                    "Design CDN cache hierarchy and content propagation",
                    "Implement CDN cache optimization for mobile and web clients"
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

# Generate content for all modules
base_path = r"d:\interview-ignite-lab\src\data\courses\system-design"
total_lessons = 0

for module_name, categories in modules.items():
    print(f"\nProcessing module: {module_name}")
    
    for category, lessons in categories.items():
        print(f"  Processing category: {category}")
        
        for slug, lesson_data in lessons.items():
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

print(f"\nSuccessfully generated content for {total_lessons} lessons across {len(modules)} modules!")