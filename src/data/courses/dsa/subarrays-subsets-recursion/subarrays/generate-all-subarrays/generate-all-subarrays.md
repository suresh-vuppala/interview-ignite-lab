# Generate All Subarrays

Generate all contiguous subarrays of a given array.

## Approach
- Two nested loops
- Outer: start index
- Inner: end index
- Print elements from start to end


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
- Time: O(n³)
- Space: O(1)

## Code

```java
public class GenerateSubarrays {
    public static void generateAllSubarrays(int[] arr) {
        int n = arr.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                System.out.print("[");
                for (int k = i; k <= j; k++) {
                    System.out.print(arr[k]);
                    if (k < j) System.out.print(", ");
                }
                System.out.println("]");
            }
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        generateAllSubarrays(arr);
    }
}
```

```python
def generate_all_subarrays(arr):
    n = len(arr)
    
    for i in range(n):
        for j in range(i, n):
            print(arr[i:j+1])

arr = [1, 2, 3]
generate_all_subarrays(arr)
```

---

```code```
