# System Design Interview Template

## The 7-Step Framework

### Step 1: Clarify Requirements (5-10 minutes)
**Goal**: Understand the problem scope and constraints

#### Functional Requirements
- What are the core features?
- Who are the users?
- What actions can users perform?

#### Non-Functional Requirements
- How many users?
- What's the expected QPS?
- What's the data size?
- What are the latency requirements?
- What's the availability requirement?

#### Example Questions:
```
"Can you clarify the scale we're designing for?"
"What are the most important features to focus on?"
"Are there any specific constraints I should consider?"
"What's the expected read/write ratio?"
```

### Step 2: Estimate Scale (5-10 minutes)
**Goal**: Calculate system capacity requirements

#### Key Metrics to Calculate:
- **QPS (Queries Per Second)**
- **Storage Requirements**
- **Bandwidth Requirements**
- **Memory Requirements**

#### Estimation Template:
```
Daily Active Users: X million
Requests per user per day: Y
Total requests per day: X * Y
QPS = (X * Y) / (24 * 3600)
Peak QPS = QPS * 3-5
```

### Step 3: High-Level Design (10-15 minutes)
**Goal**: Create the overall system architecture

#### Core Components:
- **Load Balancer**
- **Web Servers**
- **Application Servers**
- **Database**
- **Cache**
- **CDN**
- **Message Queue**

#### Design Principles:
- Start simple
- Add components as needed
- Show data flow
- Explain each component's role

### Step 4: Database Design (10-15 minutes)
**Goal**: Design data models and storage strategy

#### Database Decisions:
- SQL vs NoSQL
- Schema design
- Indexing strategy
- Partitioning/Sharding

#### Key Considerations:
- Data relationships
- Query patterns
- Consistency requirements
- Scalability needs

### Step 5: Detailed Design (10-15 minutes)
**Goal**: Deep dive into critical components

#### Focus Areas:
- API design
- Algorithms and data structures
- Caching strategy
- Security considerations

#### Common Deep Dives:
- How to handle hot data
- How to ensure data consistency
- How to handle failures
- How to optimize performance

### Step 6: Scale the Design (5-10 minutes)
**Goal**: Address scalability challenges

#### Scaling Strategies:
- **Horizontal scaling**
- **Database sharding**
- **Caching layers**
- **CDN implementation**
- **Load balancing**
- **Microservices**

#### Bottleneck Analysis:
- Identify potential bottlenecks
- Propose solutions
- Discuss trade-offs

### Step 7: Monitoring & Wrap-up (5 minutes)
**Goal**: Discuss operational concerns

#### Monitoring:
- Key metrics to track
- Alerting strategies
- Logging requirements

#### Final Review:
- Summarize the design
- Address any remaining questions
- Discuss potential improvements

---

## Interview Best Practices

### Do's ✅
- **Ask clarifying questions** - Don't assume requirements
- **Start simple** - Begin with basic architecture
- **Think out loud** - Explain your reasoning
- **Draw diagrams** - Visual representations help
- **Consider trade-offs** - Discuss pros and cons
- **Be realistic** - Use reasonable estimates
- **Stay organized** - Follow the framework

### Don'ts ❌
- **Don't jump to details** - Start with high-level design
- **Don't over-engineer** - Keep it simple initially
- **Don't ignore constraints** - Consider scale and requirements
- **Don't be silent** - Communicate your thought process
- **Don't stick to one solution** - Be flexible
- **Don't forget about failures** - Consider error scenarios

---

## Common Interview Patterns

### Pattern 1: Read-Heavy Systems
**Examples**: Social media feeds, news sites
**Key Components**: CDN, caching layers, read replicas
**Focus**: Cache strategies, data denormalization

### Pattern 2: Write-Heavy Systems
**Examples**: Logging systems, analytics
**Key Components**: Message queues, batch processing
**Focus**: Write optimization, eventual consistency

### Pattern 3: Real-Time Systems
**Examples**: Chat apps, gaming
**Key Components**: WebSockets, message brokers
**Focus**: Low latency, connection management

### Pattern 4: Search Systems
**Examples**: Search engines, recommendation systems
**Key Components**: Inverted indexes, ranking algorithms
**Focus**: Data indexing, query optimization

---

## Sample Questions by Category

### Social Media
- Design Twitter
- Design Instagram
- Design Facebook News Feed
- Design LinkedIn

### Messaging
- Design WhatsApp
- Design Slack
- Design Discord

### E-commerce
- Design Amazon
- Design payment system
- Design inventory management

### Media
- Design YouTube
- Design Netflix
- Design Spotify

### Infrastructure
- Design URL shortener
- Design CDN
- Design load balancer

---

## Time Management

### 45-Minute Interview Breakdown:
- **Requirements (8 min)**: Clarify scope and constraints
- **Estimation (7 min)**: Calculate capacity needs
- **High-Level (12 min)**: Overall architecture
- **Database (8 min)**: Data model and storage
- **Deep Dive (7 min)**: Critical components
- **Scaling (3 min)**: Address bottlenecks

### Key Time Savers:
- Use standard components (load balancer, cache, etc.)
- Focus on the most critical parts
- Don't get stuck on minor details
- Keep moving forward

---

## Communication Tips

### Effective Phrases:
- "Let me clarify the requirements..."
- "Based on the scale, I'm thinking..."
- "The trade-off here is..."
- "To handle this bottleneck, we could..."
- "Let me walk through the data flow..."

### When Stuck:
- "Can I take a step back and reconsider?"
- "What if we approach this differently?"
- "Let me think about the trade-offs here..."
- "Would it help if I explained my reasoning?"

---

## Common Mistakes to Avoid

### Technical Mistakes:
- Ignoring data consistency
- Forgetting about single points of failure
- Not considering network partitions
- Underestimating storage requirements

### Process Mistakes:
- Jumping to implementation details
- Not asking enough questions
- Spending too much time on one component
- Not explaining the reasoning

### Communication Mistakes:
- Being too quiet
- Not drawing diagrams
- Using too much jargon
- Not checking understanding

---

## Practice Strategy

### Before the Interview:
1. **Study common patterns** - Learn standard architectures
2. **Practice estimation** - Get comfortable with numbers
3. **Review case studies** - Understand real-world systems
4. **Mock interviews** - Practice with peers

### During Practice:
1. **Time yourself** - Stick to the framework
2. **Draw everything** - Practice visual communication
3. **Explain out loud** - Develop clear explanations
4. **Focus on trade-offs** - Always consider alternatives

### After Practice:
1. **Review feedback** - Identify improvement areas
2. **Study gaps** - Learn missing concepts
3. **Refine approach** - Improve your framework
4. **Build confidence** - Practice until comfortable