# Generate All Subsequences

Generate all possible subsequences maintaining relative order.

## Approach
- Use recursion with include/exclude pattern
- At each index: exclude or include element
- Base case: reached end of array

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
