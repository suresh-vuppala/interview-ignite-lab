# Generate All Subarrays

Generate all contiguous subarrays of a given array.

## Approach
- Two nested loops
- Outer: start index
- Inner: end index
- Print elements from start to end

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
