# Generate All Subsets using Recursion

Generate all possible subsets (power set) using recursion.

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

public class GenerateSubsets {
    public static void generateSubsets(int[] arr, int index, List<Integer> current, List<List<Integer>> result) {
        if (index == arr.length) {
            result.add(new ArrayList<>(current));
            return;
        }
        
        generateSubsets(arr, index + 1, current, result);
        
        current.add(arr[index]);
        generateSubsets(arr, index + 1, current, result);
        current.remove(current.size() - 1);
    }
    
    public static List<List<Integer>> subsets(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();
        generateSubsets(arr, 0, new ArrayList<>(), result);
        return result;
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        List<List<Integer>> result = subsets(arr);
        for (List<Integer> subset : result) {
            System.out.println(subset);
        }
    }
}
```

```python
def generate_subsets(arr, index, current, result):
    if index == len(arr):
        result.append(current[:])
        return
    
    generate_subsets(arr, index + 1, current, result)
    
    current.append(arr[index])
    generate_subsets(arr, index + 1, current, result)
    current.pop()

def subsets(arr):
    result = []
    generate_subsets(arr, 0, [], result)
    return result

arr = [1, 2, 3]
result = subsets(arr)
for subset in result:
    print(subset)
```
