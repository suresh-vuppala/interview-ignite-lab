import java.util.HashMap;
import java.util.Map;

public int subarraySum(int[] nums, int k) {
    int n = nums.length;
    int[] PS = new int[n + 1];
    PS[0] = 0;
    for (int i = 1; i <= n; i++) {
        PS[i] = PS[i - 1] + nums[i - 1];
    }

    Map<Integer, Integer> map = new HashMap<>();
    map.put(0, 1); // prefix sum 0 appears once (empty subarray)
    int count = 0;

    for (int end = 1; end <= n; end++) {
        int target = PS[end] - k;
        count += map.getOrDefault(target, 0);
        map.put(PS[end], map.getOrDefault(PS[end], 0) + 1);
    }
    return count;
}