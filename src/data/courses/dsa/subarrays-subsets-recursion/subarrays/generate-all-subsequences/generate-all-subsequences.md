# Generate All Subsequences

Generate all possible subsequences maintaining relative order.

## Approach
- Use recursion with include/exclude pattern
- At each index: exclude or include element
- Base case: reached end of array


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

## Complexity
- Time: O(2ⁿ)
- Space: O(n)

## Code

```java
import java.util.*;

public class GenerateSubsequences {
    public static void generateSubsequences(int[] arr, int index, List<Integer> current) {
        if (index == arr.length) {
            System.out.println(current);
            return;
        }
        
        generateSubsequences(arr, index + 1, current);
        
        current.add(arr[index]);
        generateSubsequences(arr, index + 1, current);
        current.remove(current.size() - 1);
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        generateSubsequences(arr, 0, new ArrayList<>());
    }
}
```

```python
def generate_subsequences(arr, index, current, result):
    if index == len(arr):
        result.append(current[:])
        return
    
    generate_subsequences(arr, index + 1, current, result)
    
    current.append(arr[index])
    generate_subsequences(arr, index + 1, current, result)
    current.pop()

arr = [1, 2, 3]
result = []
generate_subsequences(arr, 0, [], result)
for seq in result:
    print(seq)
```

---

```code```
