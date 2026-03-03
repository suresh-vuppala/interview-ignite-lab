def nim_game(piles): xor_sum=0; [xor_sum:=xor_sum^p for p in piles]; return xor_sum!=0
def can_win_stones(n): return n%3!=0
print(f"Nim [3,4,5]: {nim_game([3,4,5])}"); print(f"Can win with 4 stones: {can_win_stones(4)}")