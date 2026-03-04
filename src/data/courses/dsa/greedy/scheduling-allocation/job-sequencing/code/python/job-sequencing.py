def max_profit(profit, deadline):
    jobs = sorted(zip(profit, deadline), reverse=True)  # Sort by profit descending
    max_deadline = max(deadline)
    slot = [-1] * (max_deadline + 1)
    total_profit = 0
    for p, d in jobs:
        for j in range(d, 0, -1):  # Find latest available slot
            if slot[j] == -1:
                slot[j] = p
                total_profit += p
                break
    return total_profit