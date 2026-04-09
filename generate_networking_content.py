import os
import json

# Lesson definitions with titles and key topics
lessons = {
    "networking-fundamentals": {
        "network-overview": {
            "title": "Computer Networks Overview",
            "questions": [
                "Explain the OSI model and its relevance in system design interviews",
                "Design network architecture for a global e-commerce platform",
                "How would you troubleshoot network latency issues in a distributed system?",
                "Explain how packets travel from client to server across the internet"
            ]
        },
        "tcp-vs-udp": {
            "title": "TCP vs UDP Protocols",
            "questions": [
                "When would you choose UDP over TCP for a real-time gaming application?",
                "Design a video streaming service - TCP or UDP and why?",
                "Explain TCP three-way handshake and its impact on latency",
                "How does TCP handle packet loss and ordering?"
            ]
        },
        "tcp-connection-lifecycle": {
            "title": "TCP Connection Lifecycle",
            "questions": [
                "Explain the TCP connection establishment and termination process",
                "How would you optimize TCP connections for a high-traffic API?",
                "Design connection pooling for a database-heavy application",
                "What happens during TIME_WAIT state and why does it matter?"
            ]
        },
        "http-vs-https": {
            "title": "HTTP vs HTTPS",
            "questions": [
                "Design secure communication for a banking application",
                "Explain the performance impact of HTTPS vs HTTP",
                "How would you implement HTTPS for a microservices architecture?",
                "What are the trade-offs between HTTP/1.1, HTTP/2, and HTTP/3?"
            ]
        },
        "dns-basics": {
            "title": "DNS Fundamentals",
            "questions": [
                "Explain how DNS resolution works from browser to IP address",
                "Design a DNS strategy for a global application with 100M users",
                "How would you handle DNS failover for high availability?",
                "Optimize DNS lookup time for a latency-sensitive application"
            ]
        },
        "dns-caching": {
            "title": "DNS Caching Strategies",
            "questions": [
                "Design a DNS caching strategy for a CDN",
                "How would you handle DNS cache poisoning attacks?",
                "Optimize DNS TTL values for a frequently changing infrastructure",
                "Explain browser DNS cache vs OS DNS cache vs recursive resolver cache"
            ]
        },
        "ip-addressing-subnets": {
            "title": "IP Addressing and Subnets",
            "questions": [
                "Design network segmentation for a multi-tier application",
                "Explain CIDR notation and subnet calculations for system design",
                "How would you plan IP addressing for a Kubernetes cluster?",
                "Design VPC architecture for AWS with public and private subnets"
            ]
        },
        "ports-protocols": {
            "title": "Ports and Protocols",
            "questions": [
                "Explain common ports and their security implications",
                "Design firewall rules for a three-tier web application",
                "How would you handle port exhaustion in a high-traffic system?",
                "Choose appropriate ports for microservices communication"
            ]
        }
    },
    "proxies": {
        "proxy-overview": {
            "title": "Proxy Servers Overview",
            "questions": [
                "Explain the role of proxies in system architecture",
                "Design a proxy layer for a microservices platform",
                "How would you use proxies to improve security and performance?",
                "Compare different types of proxies and their use cases"
            ]
        },
        "forward-vs-reverse-proxy": {
            "title": "Forward vs Reverse Proxy",
            "questions": [
                "Design a reverse proxy setup for load balancing 1000 servers",
                "When would you use a forward proxy vs reverse proxy?",
                "Implement SSL termination using reverse proxy",
                "Design proxy architecture for a corporate network"
            ]
        },
        "service-discovery-mechanisms": {
            "title": "Service Discovery Mechanisms",
            "questions": [
                "Design service discovery for a microservices architecture with 100 services",
                "Compare client-side vs server-side service discovery",
                "Implement health checking and service registration",
                "Design service mesh for inter-service communication"
            ]
        }
    },
    "network-security": {
        "tls-ssl-handshake": {
            "title": "TLS/SSL Handshake Process",
            "questions": [
                "Explain the TLS 1.3 handshake process step by step",
                "How would you optimize TLS handshake latency?",
                "Design certificate management for a microservices platform",
                "Implement mutual TLS (mTLS) for service-to-service communication"
            ]
        },
        "https-certificates": {
            "title": "HTTPS Certificates Management",
            "questions": [
                "Design certificate rotation strategy for 1000 servers",
                "Explain certificate chain validation process",
                "How would you automate certificate renewal with Let's Encrypt?",
                "Handle certificate expiration in a zero-downtime deployment"
            ]
        },
        "firewall-security-groups": {
            "title": "Firewalls and Security Groups",
            "questions": [
                "Design firewall rules for a three-tier application in AWS",
                "Implement defense in depth with multiple firewall layers",
                "How would you handle DDoS protection with firewall rules?",
                "Design security groups for a Kubernetes cluster"
            ]
        },
        "ddos-protection": {
            "title": "DDoS Protection Strategies",
            "questions": [
                "Design DDoS mitigation for a public-facing API",
                "Implement rate limiting and traffic shaping",
                "How would you detect and respond to DDoS attacks?",
                "Design multi-layer DDoS protection with CDN and WAF"
            ]
        },
        "zero-trust-networking": {
            "title": "Zero Trust Network Architecture",
            "questions": [
                "Design a zero trust architecture for enterprise applications",
                "Implement identity-based access control for microservices",
                "How would you migrate from perimeter security to zero trust?",
                "Design zero trust networking for remote workforce"
            ]
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
> **Key Point:** Understanding {title.lower()} is essential for designing scalable, secure, and performant distributed systems.

- **Demonstrates networking fundamentals** - critical for system design
- **Shows security awareness** - essential for production systems
- **Proves practical experience** - real-world implementation knowledge
- **Foundation for architecture** - drives design decisions

### In Real Systems
> **Important:** Proper {title.lower()} implementation ensures system reliability, security, and performance.

- **Performance optimization** - reduce latency and improve throughput
- **Security hardening** - protect against attacks and vulnerabilities
- **Scalability planning** - handle growing traffic and users
- **Reliability assurance** - ensure high availability

---

## Core Concepts

> **Critical:** Master these fundamental concepts for interview success.

### Key Principles

```
Fundamental Concepts:
- Network layers and protocols
- Request/response patterns
- Connection management
- Security considerations
- Performance optimization
```

### Architecture Patterns

```
Common Patterns:
- Client-server communication
- Proxy and gateway patterns
- Load balancing strategies
- Security layers
- Caching mechanisms
```

---

## Interview Examples

### Example 1: Design Problem

**Question**: "Design a solution that demonstrates {title.lower()} in action."

> **Key Insight:** Break down the problem into components and explain trade-offs.

**Solution**:
```
1. Requirements Analysis:
   - Identify key requirements
   - Consider scale and performance
   - Security and compliance needs
   - Operational constraints

2. Architecture Design:
   - Component breakdown
   - Communication patterns
   - Data flow design
   - Failure handling

3. Implementation Details:
   - Technology choices
   - Configuration specifics
   - Monitoring and alerting
   - Scaling strategy
```

### Example 2: Performance Optimization

**Question**: "How would you optimize performance in this scenario?"

> **Important:** Consider multiple optimization strategies and their trade-offs.

**Solution**:
```
1. Identify Bottlenecks:
   - Measure current performance
   - Profile system behavior
   - Identify constraints
   - Prioritize improvements

2. Optimization Strategies:
   - Protocol optimization
   - Connection pooling
   - Caching strategies
   - Load balancing

3. Validation:
   - Performance testing
   - Monitoring metrics
   - Capacity planning
   - Continuous optimization
```

---

## Best Practices

### Do's
> **Success Patterns:** Follow these guidelines for robust implementations.

- **Design for `security`** - implement defense in depth
- **Optimize for `performance`** - minimize latency and maximize throughput
- **Plan for `scalability`** - handle growth gracefully
- **Monitor `continuously`** - track metrics and alerts
- **Test `thoroughly`** - validate under load
- **Document `clearly`** - maintain operational knowledge

### Don'ts
> **Common Pitfalls:** Avoid these mistakes in production systems.

- **Don't ignore `security`** - always implement proper controls
- **Don't skip `monitoring`** - visibility is critical
- **Don't over-engineer** - keep solutions simple
- **Don't forget `failover`** - plan for failures
- **Don't neglect `documentation`** - maintain runbooks
- **Don't ignore `performance`** - optimize early

---

## Practice Problems

> **Learn by Doing:** Apply concepts to real scenarios.

### Problem 1: System Design Challenge

**Question**: Design a system that effectively uses {title.lower()}.

**Your Task**: Create a comprehensive architecture with proper implementation.

**Hints**:
- Consider `scalability` requirements
- Think about `security` implications
- Plan for `performance` optimization
- Address `reliability` concerns

**Solution**:
```
1. Architecture Overview:
   - High-level design
   - Component breakdown
   - Communication patterns
   - Data flow

2. Implementation Details:
   - Technology stack
   - Configuration
   - Security measures
   - Monitoring setup

3. Scalability Design:
   - Horizontal scaling
   - Load balancing
   - Caching strategy
   - Database optimization

4. Operational Considerations:
   - Deployment strategy
   - Monitoring and alerting
   - Disaster recovery
   - Performance tuning
```

---

### Problem 2: Optimization Challenge

**Question**: Optimize an existing system for better performance and reliability.

**Your Task**: Identify bottlenecks and implement improvements.

**Hints**:
- Analyze `current performance`
- Identify `bottlenecks`
- Consider `trade-offs`
- Validate `improvements`

**Solution**:
```
1. Performance Analysis:
   - Baseline measurements
   - Bottleneck identification
   - Resource utilization
   - Latency breakdown

2. Optimization Strategy:
   - Quick wins
   - Long-term improvements
   - Infrastructure changes
   - Code optimizations

3. Implementation Plan:
   - Prioritized changes
   - Testing strategy
   - Rollout plan
   - Rollback procedures

4. Validation:
   - Performance testing
   - Load testing
   - Monitoring setup
   - Success metrics
```

---

## References and Further Reading

### Essential Resources
| Resource | Description |
|----------|-------------|
| [RFC Documentation](https://www.rfc-editor.org/) | Official protocol specifications |
| [High Performance Browser Networking](https://hpbn.co/) | Comprehensive networking guide |
| [System Design Primer](https://github.com/donnemartin/system-design-primer) | System design fundamentals |

### Industry Case Studies
| Company | Resource | Focus |
|---------|----------|-------|
| Netflix | [Tech Blog](https://netflixtechblog.com/) | Networking at scale |
| Cloudflare | [Blog](https://blog.cloudflare.com/) | Network security and performance |
| AWS | [Architecture Blog](https://aws.amazon.com/blogs/architecture/) | Cloud networking patterns |

### Tools and Technologies
| Tool | Description |
|------|-------------|
| [Wireshark](https://www.wireshark.org/) | Network protocol analyzer |
| [tcpdump](https://www.tcpdump.org/) | Command-line packet analyzer |
| [curl](https://curl.se/) | Command-line HTTP client |

---

## Deep Dive Topics

### Advanced Concepts
- **Protocol Internals** - Deep dive into protocol specifications
- **Performance Tuning** - Advanced optimization techniques
- **Security Hardening** - Defense in depth strategies

### Related Topics for Deep Dive

- **[Load Balancing](../../load-balancing/load-balancing-essentials/intro-load-balancing)** - Distribute traffic effectively
- **[Caching](../../caching/caching-fundamentals/caching-basics)** - Optimize performance
- **[API Design](../../api-layer/api-design-communication/introduction-to-apis)** - Design effective interfaces
- **[Performance Metrics](../../system-design-foundations/scaling-performance-basics/performance-metrics)** - Monitor system health
"""

def update_json_file(json_path):
    with open(json_path, 'r') as f:
        data = json.load(f)
    
    data['isPosted'] = True
    
    with open(json_path, 'w') as f:
        json.dump(data, f, indent=2)

# Generate content for all lessons
base_path = r"d:\interview-ignite-lab\src\data\courses\system-design\networking-proxy"

for category, category_lessons in lessons.items():
    for slug, lesson_data in category_lessons.items():
        lesson_path = os.path.join(base_path, category, slug)
        md_file = os.path.join(lesson_path, f"{slug}.md")
        json_file = os.path.join(lesson_path, f"{slug}.json")
        
        # Generate and write markdown content
        content = generate_lesson_content(lesson_data['title'], lesson_data['questions'])
        with open(md_file, 'w', encoding='utf-8') as f:
            f.write(content)
        
        # Update JSON to mark as posted
        update_json_file(json_file)
        
        print(f"Generated: {lesson_data['title']}")

print(f"\nSuccessfully generated content for {sum(len(v) for v in lessons.values())} lessons!")
