# Twitter System Design: Functional Requirements

## Interview Conversation

**Interviewer**: "Let's start with functional requirements. What features do you think we need to support for Twitter?"

**Candidate**: "Great question. Let me think through the core user journeys and features. I'll organize this by user actions and then we can prioritize what's most important for our design.

### Core Features I'm Thinking Of:

**User Management:**
- User registration and authentication
- User profiles with bio, profile picture, follower/following counts

**Tweet Operations:**
- Post tweets (text, up to 280 characters)
- View tweets
- Delete own tweets
- Edit tweets (if we want to support this)

**Social Interactions:**
- Follow/unfollow other users
- Like tweets
- Retweet (share others' tweets)
- Reply to tweets
- Quote tweets

**Timeline & Discovery:**
- Home timeline (tweets from followed users)
- User profile timeline (user's own tweets)
- Search tweets by keywords
- Trending topics

Let me pause here - which of these would you like me to focus on? Are there any you'd consider out of scope for this interview?"

**Interviewer**: "That's a comprehensive list. For this interview, let's focus on the core functionality: posting tweets, following users, and generating the home timeline. We can consider likes and retweets as nice-to-have. What about media - should we support images and videos?"

**Candidate**: "Good clarification. For media, I'd suggest we start with text-only tweets to keep the core design focused, but I'll design the system in a way that we can easily add media support later. Does that work?

So our **core functional requirements** are:
1. **Post tweets** (text only, 280 characters max)
2. **Follow/unfollow users**
3. **Generate home timeline** (tweets from followed users)
4. **View user profiles** and their tweets

And **nice-to-have features** we might discuss if time permits:
- Likes and retweets
- Media attachments
- Search functionality

Is this the right scope for our discussion?"

**Interviewer**: "Perfect. Now, let's think about the user experience. How should the timeline work? Should it be real-time, or is some delay acceptable?"

---

## Detailed Functional Requirements Analysis

### 1. Tweet Posting

**Candidate's Deep Dive**:
"Let me think through the tweet posting flow:

**User Story**: As a user, I want to post a tweet so that my followers can see my thoughts.

**Detailed Requirements**:
- **Input validation**: 280 character limit, no empty tweets
- **Content processing**: Handle mentions (@username), hashtags (#topic)
- **Timestamp**: Record when the tweet was created
- **Unique identification**: Each tweet needs a unique ID
- **Immediate feedback**: User should see their tweet posted immediately
- **Durability**: Once posted, the tweet should be permanently stored

**Edge Cases to Consider**:
- What if the user posts the exact same tweet twice?
- Should we support draft tweets?
- What happens if posting fails - do we retry?

**Interviewer**: "Good thinking on edge cases. For duplicates, let's allow them for now - users might want to post the same thing at different times. No need for drafts in our core design."

### 2. Follow/Unfollow System

**Candidate's Analysis**:
"For the social graph:

**User Story**: As a user, I want to follow other users so I can see their tweets in my timeline.

**Detailed Requirements**:
- **Follow action**: User A can follow User B
- **Unfollow action**: User A can unfollow User B
- **Bidirectional visibility**: 
  - User A sees User B's tweets in timeline
  - User B sees User A in their followers list
- **Follow counts**: Display follower and following counts on profiles
- **Privacy**: For now, assume all accounts are public (no private accounts)

**Questions for Clarification**:
- Should there be a limit on how many people you can follow?
- Do we need to prevent users from following themselves?
- Should we support follow requests for private accounts?

**Interviewer**: "Let's keep it simple - no follow limits, users can't follow themselves, and all accounts are public."

### 3. Home Timeline Generation

**Candidate's Deep Analysis**:
"This is the most complex feature. Let me break it down:

**User Story**: As a user, I want to see a timeline of recent tweets from people I follow, ordered by recency.

**Detailed Requirements**:
- **Content source**: Tweets from all users that the current user follows
- **Ordering**: Most recent tweets first (reverse chronological)
- **Pagination**: Load tweets in batches (e.g., 20 at a time)
- **Real-time updates**: How fresh should the timeline be?
- **Performance**: Timeline should load quickly (< 200ms)

**Critical Questions**:
1. **Freshness**: Should new tweets appear immediately, or is a few seconds delay okay?
2. **Volume**: What if a user follows someone who tweets 100 times per day?
3. **Inactive users**: Should we show tweets from users who haven't been active recently?

**Interviewer**: "Great questions. Let's say a few seconds delay is acceptable - we don't need real-time updates. For high-volume users, show all their tweets but we can discuss optimization later. Include all tweets regardless of user activity."

**Candidate**: "Perfect. So the timeline requirements are:
- **Aggregation**: Collect tweets from all followed users
- **Sorting**: Order by creation time (newest first)
- **Pagination**: Support cursor-based pagination for infinite scroll
- **Freshness**: Updates within a few seconds are acceptable
- **Performance**: Target < 200ms load time for timeline requests"

### 4. User Profiles

**Candidate's Analysis**:
"For user profiles:

**User Story**: As a user, I want to view other users' profiles to see their information and tweets.

**Requirements**:
- **Profile information**: Username, display name, bio, join date
- **Statistics**: Follower count, following count, tweet count
- **Tweet history**: User's tweets in reverse chronological order
- **Follow button**: Ability to follow/unfollow from profile page

**Performance Considerations**:
- Profile pages are likely to be cached heavily
- Tweet counts might be expensive to calculate in real-time"

---

## Requirements Summary & Prioritization

**Candidate**: "Let me summarize our functional requirements in order of priority:

### Must-Have (Core MVP):
1. **User Authentication & Profiles**
   - Register, login, basic profile info
   - View other users' profiles

2. **Tweet Operations**
   - Post text tweets (≤ 280 characters)
   - View individual tweets
   - Display tweets on user profiles

3. **Social Graph**
   - Follow/unfollow users
   - Track follower/following relationships

4. **Home Timeline**
   - Aggregate tweets from followed users
   - Display in reverse chronological order
   - Support pagination

### Nice-to-Have (Future Iterations):
1. **Engagement Features**
   - Like tweets
   - Retweet functionality
   - Reply to tweets

2. **Discovery Features**
   - Search tweets
   - Trending topics
   - User recommendations

3. **Rich Content**
   - Image/video attachments
   - Link previews

### Explicitly Out of Scope:
- Direct messaging
- Notifications
- Analytics/insights
- Advertising system
- Content moderation (beyond basic validation)

Does this prioritization align with your expectations?"

**Interviewer**: "Excellent breakdown. I like how you've prioritized the core social media loop: post content, build social graph, consume content. This gives us a solid foundation to work with. Let's move on to non-functional requirements."

---

## Key Insights & Decisions

### Design Implications

**Candidate's Reflection**:
"Based on these functional requirements, I can already see some key design challenges:

1. **Timeline Generation Complexity**: This will likely be our biggest scalability challenge
2. **Social Graph Storage**: We need efficient storage and querying of follow relationships  
3. **Tweet Storage**: Simple but needs to scale to billions of tweets
4. **User Experience**: Balance between freshness and performance

These requirements will drive our architecture decisions in the next phases."

### Questions for Later Phases

**Candidate's Notes**:
"As we move forward, I'll need to consider:
- How do we efficiently generate timelines for users who follow thousands of people?
- How do we handle celebrity users with millions of followers?
- What's our strategy for data consistency vs. availability?
- How do we partition data across multiple databases?"

**Interviewer**: "Those are exactly the right questions to be thinking about. You're setting yourself up well for the system design phase. Let's talk about scale and non-functional requirements next."

---

## Functional Requirements Checklist

✅ **Core user journeys defined**  
✅ **Feature prioritization established**  
✅ **Edge cases considered**  
✅ **Performance expectations set**  
✅ **Scope boundaries clarified**  
✅ **Design implications identified**

**Next**: Non-functional requirements and capacity estimation to understand the scale we're designing for.