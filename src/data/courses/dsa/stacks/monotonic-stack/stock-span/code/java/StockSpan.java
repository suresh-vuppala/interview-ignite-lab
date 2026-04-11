// ============================================================
// Online Stock Span
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N) per call | Space: O(N)
// ============================================================
class StockSpanner1 {
    List<Integer> prices = new ArrayList<>();

    public int next(int price) {
        prices.add(price);
        int span = 1, i = prices.size() - 2;
        while (i >= 0 && prices.get(i) <= price) { span++; i--; }
        return span;
    }
}

// ============================================================
// Solution 2: Monotonic Stack (Optimal)
// Time: O(1) amortized | Space: O(N)
// ============================================================
class StockSpanner2 {
    Deque<int[]> stack = new ArrayDeque<>(); // [price, index]
    int day = 0;

    public int next(int price) {
        while (!stack.isEmpty() && stack.peek()[0] <= price)
            stack.pop();

        int span = stack.isEmpty() ? day + 1 : day - stack.peek()[1];
        stack.push(new int[]{price, day});
        day++;
        return span;
    }
}
