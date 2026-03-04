def least_interval(tasks, n):
    freq = [0] * 26
    for task in tasks:
        freq[ord(task) - ord('A')] += 1
    
    freq.sort()
    max_freq = freq[25]  # Most frequent task
    idle_slots = (max_freq - 1) * n  # Idle slots needed
    
    for i in range(24, -1, -1):
        if idle_slots <= 0:
            break
        idle_slots -= min(max_freq - 1, freq[i])  # Fill idle slots
    
    return len(tasks) + max(0, idle_slots)