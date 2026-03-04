def can_complete_circuit(gas, cost):
    total, current, start = 0, 0, 0
    for i in range(len(gas)):
        total += gas[i] - cost[i]  # Total gas balance
        current += gas[i] - cost[i]  # Current gas balance
        if current < 0:  # Can't reach next station
            start = i + 1  # Try starting from next station
            current = 0
    return start if total >= 0 else -1  # If total >= 0, solution exists