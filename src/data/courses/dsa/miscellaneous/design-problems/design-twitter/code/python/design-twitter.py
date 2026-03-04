import heapq
from collections import defaultdict

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)  # userId -> list of (timestamp, tweetId)
        self.following = defaultdict(set)  # userId -> set of followeeIds
    
    def postTweet(self, userId, tweetId):
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1
    
    def getNewsFeed(self, userId):
        heap = []
        
        # Add user's own tweets
        if userId in self.tweets:
            idx = len(self.tweets[userId]) - 1
            ts, tid = self.tweets[userId][idx]
            heapq.heappush(heap, (-ts, tid, userId, idx))  # Max heap by timestamp
        
        # Add followees' tweets
        for followeeId in self.following[userId]:
            if followeeId in self.tweets:
                idx = len(self.tweets[followeeId]) - 1
                ts, tid = self.tweets[followeeId][idx]
                heapq.heappush(heap, (-ts, tid, followeeId, idx))
        
        result = []
        while heap and len(result) < 10:
            ts, tid, uid, idx = heapq.heappop(heap)
            result.append(tid)
            next_idx = idx - 1
            if next_idx >= 0:  # Add next tweet from same user
                ts, tid = self.tweets[uid][next_idx]
                heapq.heappush(heap, (-ts, tid, uid, next_idx))
        return result
    
    def follow(self, followerId, followeeId):
        if followerId != followeeId:
            self.following[followerId].add(followeeId)
    
    def unfollow(self, followerId, followeeId):
        self.following[followerId].discard(followeeId)