def minimum_card_pickup(cards):
    mp = {}
    min_len = float('inf')
    for i in range(len(cards)):
        if cards[i] in mp:
            min_len = min(min_len, i - mp[cards[i]] + 1)
        mp[cards[i]] = i
    return -1 if min_len == float('inf') else min_len