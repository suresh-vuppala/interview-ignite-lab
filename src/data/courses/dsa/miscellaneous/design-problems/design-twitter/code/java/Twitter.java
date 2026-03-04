class Twitter {
    private int timestamp = 0;
    private Map<Integer, List<int[]>> tweets; // userId -> list of [timestamp, tweetId]
    private Map<Integer, Set<Integer>> following; // userId -> set of followeeIds
    
    public Twitter() {
        tweets = new HashMap<>();
        following = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        tweets.putIfAbsent(userId, new ArrayList<>());
        tweets.get(userId).add(new int[]{timestamp++, tweetId});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]); // Max heap by timestamp
        
        // Add user's own tweets
        if (tweets.containsKey(userId)) {
            List<int[]> userTweets = tweets.get(userId);
            int idx = userTweets.size() - 1;
            if (idx >= 0) pq.offer(new int[]{userTweets.get(idx)[0], userTweets.get(idx)[1], userId, idx});
        }
        
        // Add followees' tweets
        if (following.containsKey(userId)) {
            for (int followeeId : following.get(userId)) {
                if (tweets.containsKey(followeeId)) {
                    List<int[]> followeeTweets = tweets.get(followeeId);
                    int idx = followeeTweets.size() - 1;
                    if (idx >= 0) pq.offer(new int[]{followeeTweets.get(idx)[0], followeeTweets.get(idx)[1], followeeId, idx});
                }
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!pq.isEmpty() && result.size() < 10) {
            int[] curr = pq.poll();
            result.add(curr[1]); // Add tweetId
            int nextIdx = curr[3] - 1;
            if (nextIdx >= 0) { // Add next tweet from same user
                List<int[]> userTweets = tweets.get(curr[2]);
                pq.offer(new int[]{userTweets.get(nextIdx)[0], userTweets.get(nextIdx)[1], curr[2], nextIdx});
            }
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following.putIfAbsent(followerId, new HashSet<>());
        following.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (following.containsKey(followerId)) {
            following.get(followerId).remove(followeeId);
        }
    }
}