A simple, intuitive, repeatable structure for designing any system — from small internal tools to large-scale distributed systems.

This framework helps you think in the correct order so you never feel lost in a system design interview or real project.

---

# 1. Clarify Functional Requirements  
**Functional Requirements = What the system must do.**

These define **core features and user actions**.

### 🎯 Goals for This Step
- Understand **who** the users are
- Understand **what** they want to accomplish
- Define what the system must **enable**, **store**, **allow**, **restrict**

### 📝 What to Write
- Core use cases  
- User flows  
- Primary actions  
- What inputs/outputs are expected  

### Example (URL Shortener)
- User enters a long URL  
- System generates short URL  
- Clicking short URL redirects to original  
- Track click analytics  

---

# 2. Clarify Non-Functional Requirements  
**Non-Functional Requirements = System behaviors under load.**

These define expectations around:
- Speed  
- Scale  
- Reliability  
- Security  
- Cost  
- Availability  

### 🎯 Goals for This Step
Set clear boundaries for **how well** the system must perform.

### 📝 What to Write
- Target user scale  
- Latency requirements  
- Availability SLA  
- Throughput (QPS, RPS)  
- Data retention  
- Consistency model (Strong/Eventual)  

### Example (URL Shortener)
- Handle 10M requests/day  
- Latency < 100ms  
- 99.99% uptime  
- Strong consistency for writes  

---

# 3. Resource Estimation (Optional but Powerful)  
This helps you figure out:
- DB size  
- Traffic volume  
- Number of servers required  
- Cache size  
- Expected growth  

### 🎯 Goals for This Step
Plan capacity logically so design decisions make sense.

### 📝 What to Include
- Read/write QPS  
- Storage per user  
- Daily data growth  
- Bandwidth estimation  

### Example
- 5M new URLs/day  
- Each URL entry ≈ 500 bytes  
- Daily storage ≈ 2.5 GB  

---

# 4. Core Entities + API Endpoint Design  
Now define the **building blocks**:

##  Core Entities  
Identify the main objects that need to be stored.

### Example (URL Shortener)
- URL  
- User (optional)  
- Analytics record  

###  What to Write
- Entity name  
- Fields  
- Relationships  

---

## 🌐 API Endpoints  
Start defining how the system is used externally.

### Format
POST /shorten
GET /{shortURL}
GET /analytics/{shortURL}


### For Each API Include:
- Request format  
- Response format  
- Validation rules  
- Success + error codes  

---

# 5. High-Level Design (HLD)
This is the **bird’s-eye view** of the system.

Ask:  
“What are the main pieces, and how do they talk to each other?”

### 🎯 Goals for This Step
Show the system’s major components:
- Client  
- API Gateway  
- Services (Auth, URL Service, Analytics)  
- Cache  
- Database  
- Load balancer  
- CDN  

### 📝 What to Include
- High-level diagram  
- Data flow (step-by-step)  
- Justification for components (cache, queue, etc.)

### Example (Text Description)
Client → Load Balancer → URL Service → Cache → Database
↘ Analytics → Queue → Storage


---

# 6. Detailed Design (Deep Dive)
In this section, you zoom into the **hard problems**.

Pick 2–4 critical areas and explain them deeply:
- Scaling strategy  
- Database design  
- Sharding  
- Caching layers  
- Queue design  
- Consistency handling  
- Failover & replication  
- API performance optimization  

### 🎯 Goals for This Step
Show that you understand:
- **How** the system scales  
- **Why** you picked certain technologies  
- **How** data flows under pressure  
- **How** failures are handled  

### 📝 What to Explain in Detail
- Storage engine choice  
- Indexing strategy  
- Cache invalidation  
- Write/read optimization  
- Replication architecture  
- Partitioning scheme  
- Failure modes and recovery path  

---



