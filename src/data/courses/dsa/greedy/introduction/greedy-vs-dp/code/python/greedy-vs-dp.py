def max_activities(start, end):
    # Greedy: Activity Selection - Choose activities that finish earliest
    end.sort()  # Sort by end time
    count, last_end = 1, end[0]
    for i in range(1, len(end)):
        if start[i] >= last_end:  # No overlap with previous activity
            count += 1
            last_end = end[i]
    return count

def knapsack(wt, val, W):
    # DP: 0/1 Knapsack - Need to consider all possibilities
    n = len(wt)
    dp = [0] * (W + 1)  # dp[w] = max value with weight w
    for i in range(n):
        for w in range(W, wt[i] - 1, -1):  # Iterate backwards to avoid using same item twice
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i])
    return dp[W]