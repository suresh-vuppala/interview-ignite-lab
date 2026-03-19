# Twitter System Design: Interview Framework & Approach

## Interview Setting
**Level**: Staff Software Engineer at Google  
**Duration**: 45 minutes  
**Focus**: System design, scalability, and architectural thinking

---

## Opening Conversation

**Interviewer**: "Today we're going to design Twitter. Before we start, can you tell me what you understand by the problem and how you'd like to approach this?"

**Candidate**: "Great! Let me start by clarifying what we mean by 'Twitter' and then outline my approach for the next 45 minutes.

When I think of Twitter, I'm thinking of a social media platform where users can:
- Post short messages (tweets)
- Follow other users
- See a timeline of tweets from people they follow
- Interact with tweets through likes, retweets, and replies

For my approach, I'd like to follow a structured framework:

1. **Requirements Clarification** (8-10 minutes)
   - Functional requirements - what features exactly
   - Non-functional requirements - scale, performance, availability
   - Out of scope items

2. **Capacity Estimation** (5-7 minutes)
   - User scale, tweet volume, storage needs
   - QPS calculations for reads and writes

3. **System Design** (20-25 minutes)
   - High-level architecture
   - Database design
   - Deep dive into critical components
   - API design

4. **Scale & Optimization** (5-8 minutes)
   - Bottlenecks identification
   - Scaling strategies
   - Trade-offs discussion

Does this approach work for you? Are there any specific areas you'd like me to focus more on?"

**Interviewer**: "That sounds like a solid approach. I particularly want to see how you handle the timeline generation problem since that's one of the most challenging aspects. Let's start with requirements."

---

## Framework Deep Dive

### 1. Requirements Gathering Strategy

**Candidate's Thought Process**:
"I always start with requirements because it sets the foundation for everything else. I'll ask clarifying questions to understand:
- **Scope**: What features are in/out of scope
- **Scale**: How big is this system
- **Performance**: What are the expectations
- **Constraints**: Any technical or business constraints"

### 2. Capacity Estimation Approach

**Candidate's Thought Process**:
"For capacity estimation, I follow a systematic approach:
- Start with user numbers (total, daily active)
- Calculate write operations (tweets, follows)
- Calculate read operations (timeline views, profile views)
- Estimate storage needs (tweets, user data, media)
- Calculate bandwidth requirements
- Always state my assumptions clearly"

### 3. System Design Philosophy

**Candidate's Thought Process**:
"For system design, I believe in:
- **Start simple**: Begin with a basic architecture
- **Identify bottlenecks**: Where will the system break first?
- **Scale incrementally**: Add complexity only when needed
- **Consider trade-offs**: Every decision has pros and cons
- **Think about operations**: How will this run in production?"

### 4. Deep Dive Selection

**Candidate's Thought Process**:
"I'll choose deep dive topics based on:
- **System criticality**: What's most important for the system to work?
- **Technical complexity**: What's the most challenging to implement?
- **Interviewer interest**: What does the interviewer want to explore?
- **My expertise**: Where can I demonstrate deep knowledge?"

---

## Key Success Factors

### Technical Excellence
- **Systematic thinking**: Follow a logical progression
- **Scalability focus**: Always think about growth
- **Trade-off analysis**: Understand pros and cons
- **Real-world experience**: Reference actual systems

### Communication Skills
- **Clear explanations**: Make complex concepts simple
- **Visual thinking**: Draw diagrams and flows
- **Interactive approach**: Engage with the interviewer
- **Assumption stating**: Be explicit about what you assume

### Problem-Solving Approach
- **Break down complexity**: Divide big problems into smaller ones
- **Iterative refinement**: Start simple, add complexity
- **Multiple solutions**: Consider different approaches
- **Practical considerations**: Think about implementation reality

---

## Common Pitfalls to Avoid

### Technical Pitfalls
❌ **Jumping to implementation details too early**
✅ **Start with high-level architecture first**

❌ **Ignoring non-functional requirements**
✅ **Consider scale, performance, and reliability from the start**

❌ **Over-engineering the initial design**
✅ **Begin with simple solutions, then scale**

❌ **Not considering failure scenarios**
✅ **Think about what happens when components fail**

### Communication Pitfalls
❌ **Being silent while thinking**
✅ **Think out loud and explain your reasoning**

❌ **Not asking clarifying questions**
✅ **Engage with the interviewer to understand requirements**

❌ **Sticking to one approach rigidly**
✅ **Be flexible and consider alternatives**

❌ **Not managing time effectively**
✅ **Keep track of time and adjust depth accordingly**

---

## Interview Mindset

### Before Starting
**Candidate's Internal Checklist**:
- "Do I understand the problem clearly?"
- "What are the most critical aspects to focus on?"
- "How can I demonstrate my experience and knowledge?"
- "What questions should I ask to clarify requirements?"

### During the Interview
**Candidate's Ongoing Thoughts**:
- "Am I explaining my reasoning clearly?"
- "Is the interviewer following my logic?"
- "Should I go deeper here or move to the next topic?"
- "What trade-offs should I highlight?"

### Handling Uncertainty
**Candidate's Approach**:
"When I'm unsure about something, I'll:
1. State what I know for certain
2. Explain what I'm uncertain about
3. Make reasonable assumptions
4. Ask for guidance if needed
5. Proceed with the assumption and note we can revisit"

---

## Time Management Strategy

### 45-Minute Breakdown
```
0-10 min:  Requirements & Clarification
10-15 min: Capacity Estimation
15-35 min: System Design (High-level + Deep dive)
35-40 min: Scaling & Optimization
40-45 min: Q&A and Wrap-up
```

### Flexible Adaptation
**Candidate's Strategy**:
"I'll adjust timing based on:
- Interviewer's interests and questions
- Complexity of topics that emerge
- Areas where I can add most value
- Natural conversation flow"

---

## Setting Expectations

**Candidate**: "Before we dive into requirements, let me set some expectations:

1. **Assumptions**: I'll make reasonable assumptions and state them clearly. Please correct me if any don't align with what you have in mind.

2. **Scope**: Given our time constraint, I'll focus on the core functionality first, then expand if we have time.

3. **Detail Level**: I'll start with high-level concepts and can dive deeper into any area you find interesting.

4. **Questions**: I'll ask questions throughout to ensure I'm on the right track. Please feel free to guide me if you want to explore specific areas.

5. **Real-world Context**: I'll try to reference real-world systems and trade-offs where relevant.

Does this approach work for you?"

**Interviewer**: "Perfect. That shows good planning and communication. Let's start with the functional requirements."

---

## Next Steps

This framework sets us up for success in the following lessons:
- **Functional Requirements**: What exactly are we building?
- **Non-Functional Requirements**: How big and how fast?
- **Entities & APIs**: What's our data model and interface?
- **High-Level Design**: What's our overall architecture?
- **Deep Dive**: How do we solve the hardest problems?
- **Trade-offs**: What are the alternatives and their implications?

The key is to maintain this structured, communicative approach throughout the entire interview while demonstrating deep technical knowledge and practical experience.