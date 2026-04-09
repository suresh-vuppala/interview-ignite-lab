import os
import json

lessons = [
    {
        "section": "scheduling-allocation",
        "slug": "gas-station",
        "title": "Gas Station",
        "md": """## Problem Statement

Find starting gas station to complete circular route.

## Approach

1. If total gas < total cost, no solution
2. Track current gas, reset start when negative

## Complexity

- Time: O(n)
- Space: O(1)

## Code

```code```""",
        "java": """class GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0, current = 0, start = 0;
        for (int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];
            if (current < 0) {
                start = i + 1;
                current = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
}""",
        "cpp": """class GasStation {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, current = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];
            if (current < 0) {
                start = i + 1;
                current = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};""",
        "python": """def can_complete_circuit(gas, cost):
    total, current, start = 0, 0, 0
    for i in range(len(gas)):
        total += gas[i] - cost[i]
        current += gas[i] - cost[i]
        if current < 0:
            start = i + 1
            current = 0
    return start if total >= 0 else -1"""
    },
    {
        "section": "others",
        "slug": "jump-game",
        "title": "Jump Game",
        "md": """## Problem Statement

Determine if you can reach the last index from first index.

## Approach

Track maximum reachable index while iterating.

## Complexity

- Time: O(n)
- Space: O(1)

## Code

```code```""",
        "java": """class JumpGame {
    public boolean canJump(int[] nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach) return false;
            maxReach = Math.max(maxReach, i + nums[i]);
        }
        return true;
    }
}""",
        "cpp": """class JumpGame {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};""",
        "python": """def can_jump(nums):
    max_reach = 0
    for i in range(len(nums)):
        if i > max_reach:
            return False
        max_reach = max(max_reach, i + nums[i])
    return True"""
    },
    {
        "section": "others",
        "slug": "jump-game-ii",
        "title": "Jump Game II",
        "md": """## Problem Statement

Find minimum number of jumps to reach last index.

## Approach

Use greedy BFS-like approach tracking current and next reach.

## Complexity

- Time: O(n)
- Space: O(1)

## Code

```code```""",
        "java": """class JumpGameII {
    public int jump(int[] nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
}""",
        "cpp": """class JumpGameII {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};""",
        "python": """def jump(nums):
    jumps, current_end, farthest = 0, 0, 0
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])
        if i == current_end:
            jumps += 1
            current_end = farthest
    return jumps"""
    },
    {
        "section": "others",
        "slug": "remove-k-digits",
        "title": "Remove K Digits",
        "md": """## Problem Statement

Remove k digits from number to get smallest possible number.

## Approach

Use stack, remove digits when current < top.

## Complexity

- Time: O(n)
- Space: O(n)

## Code

```code```""",
        "java": """class RemoveKDigits {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while (k-- > 0) stack.pop();
        
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) sb.append(stack.pop());
        sb.reverse();
        
        while (sb.length() > 1 && sb.charAt(0) == '0') sb.deleteCharAt(0);
        return sb.length() == 0 ? "0" : sb.toString();
    }
}""",
        "cpp": """class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k-- > 0) stack.pop_back();
        
        int start = 0;
        while (start < stack.size() && stack[start] == '0') start++;
        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};""",
        "python": """def remove_k_digits(num, k):
    stack = []
    for c in num:
        while stack and k > 0 and stack[-1] > c:
            stack.pop()
            k -= 1
        stack.append(c)
    while k > 0:
        stack.pop()
        k -= 1
    result = ''.join(stack).lstrip('0')
    return result if result else '0'"""
    }
]

base_path = "src/data/courses/dsa/greedy"

for lesson in lessons:
    lesson_path = os.path.join(base_path, lesson["section"], lesson["slug"])
    code_path = os.path.join(lesson_path, "code")
    
    os.makedirs(os.path.join(code_path, "java"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "cpp"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "python"), exist_ok=True)
    
    with open(os.path.join(lesson_path, f"{lesson['slug']}.md"), "w", encoding="utf-8") as f:
        f.write(lesson["md"])
    
    json_content = {
        "title": lesson["title"],
        "description": lesson["title"],
        "difficulty": "medium",
        "isPremium": False,
        "isPosted": True
    }
    with open(os.path.join(lesson_path, f"{lesson['slug']}.json"), "w", encoding="utf-8") as f:
        json.dump(json_content, f, indent=4)
    
    class_name = ''.join(word.capitalize() for word in lesson['slug'].split('-'))
    
    with open(os.path.join(code_path, "java", f"{class_name}.java"), "w") as f:
        f.write(lesson["java"])
    
    with open(os.path.join(code_path, "cpp", f"{class_name}.cpp"), "w") as f:
        f.write(lesson["cpp"])
    
    with open(os.path.join(code_path, "python", f"{lesson['slug']}.py"), "w") as f:
        f.write(lesson["python"])

print(f"Created {len(lessons)} greedy lessons (part 3)")
