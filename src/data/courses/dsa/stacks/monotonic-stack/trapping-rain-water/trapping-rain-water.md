Calculate how much water can be trapped after raining given elevation map.

<br>

> Input:
> height = [0,1,0,2,1,0,1,3,2,1,2,1]

> Output:
> 6

> Explanation:
> Water trapped visualization:
>        █
>    █www█w█
> _█w█w█████
> 
> Water units: 1+1+2+1+1 = 6
> - At index 2: min(max_left=1, max_right=2) - height=0 = 1
> - At index 4: min(max_left=2, max_right=3) - height=1 = 1
> - At index 5: min(max_left=2, max_right=3) - height=0 = 2

<br>

---

## Solution: Two Pointer Approach

Use two pointers to track max heights:
1. Left and right pointers at ends
2. Track leftMax and rightMax
3. Move pointer with smaller max
4. Water at position = min(leftMax, rightMax) - height

**Key insight:** Water level determined by minimum of max heights on both sides.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Two pointers traverse array once
- Each element processed exactly once
- No nested loops

**Space Complexity: O(1)**
- Only use constant extra space
- Two pointers + two max variables
- No additional data structures

**Alternative stack approach: O(n) time, O(n) space**
- Stack stores indices
- Calculate water when popping
- Less space efficient than two pointers

> **Time Complexity:** O(n) - single pass
> **Space Complexity:** O(1) - constant space

<br>
<br>

---