def dec_to_bin(n): return bin(n)[2:]
def bin_to_dec(s): return int(s,2)
def is_power_of_two(n): return n>0 and n&(n-1)==0
def count_set_bits(n): c=0; [c:=c+1 or (n:=n&(n-1)) for _ in iter(lambda:n,0)]; return c
def fast_pow(a, b): r=1; [(r:=r*a if b&1 else r) or (a:=a*a) or (b:=b>>1) for _ in iter(lambda:b,0)]; return r
print(f"13 to binary: {dec_to_bin(13)}"); print(f"1101 to decimal: {bin_to_dec('1101')}"); print(f"16 is power of 2: {is_power_of_two(16)}"); print(f"Set bits in 13: {count_set_bits(13)}"); print(f"2^10: {fast_pow(2,10)}")