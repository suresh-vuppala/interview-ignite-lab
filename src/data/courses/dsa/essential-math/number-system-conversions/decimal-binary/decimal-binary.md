## Overview
Convert between decimal and binary number systems, check power of two, count set bits, and perform fast exponentiation.

## Topics Covered
1. **Decimal to Binary**: Convert decimal to binary string
2. **Binary to Decimal**: Convert binary string to decimal
3. **Power of Two Check**: Check if number is power of 2
4. **Count Set Bits**: Count 1s in binary representation
5. **Fast Exponentiation**: Compute a^b efficiently

## Approach

### Decimal to Binary
- Repeatedly divide by 2, collect remainders
- Time: O(log n)

### Power of Two
- n & (n-1) == 0 and n != 0
- Time: O(1)

### Count Set Bits
- Use Brian Kernighan's algorithm: n & (n-1)
- Time: O(number of set bits)

### Fast Exponentiation
- Binary exponentiation: a^b = (a^2)^(b/2) if b even
- Time: O(log b)

## Complexity Analysis
### Time: O(log n), Space: O(1)

## Code
```code```