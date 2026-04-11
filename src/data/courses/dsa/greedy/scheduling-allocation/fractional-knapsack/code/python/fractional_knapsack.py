def fractional_knapsack(W, items):
    items.sort(key=lambda x: x[0]/x[1], reverse=True)  # Sort by val/wt ratio
    total = 0
    for val, wt in items:
        if W >= wt: total += val; W -= wt
        else: total += val * (W / wt); break
    return total