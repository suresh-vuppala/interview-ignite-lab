## Prefix Sum — O(1) Range Queries

Prefix sum is a technique to preprocess an array so that any **subarray sum** can be computed in O(1) time. It's the foundation for many subarray problems.

<br>

## Core Idea

Build a prefix array where `prefix[i] = sum(nums[0..i-1])`. Then:
- **Sum of subarray [l, r]** = `prefix[r+1] - prefix[l]`
- **Subarray sum equals K** → Find `prefix[j] - prefix[i] == K` using a hash map

<br>

## When to Use Prefix Sum

| Signal in Problem | Technique |
|-------------------|-----------|
| "Subarray sum equals K" | Prefix sum + hash map |
| "Range sum query" | Prefix array |
| "Count subarrays with sum divisible by K" | Prefix sum mod + hash map |
| "Longest subarray with sum K" | Prefix sum + first occurrence map |
| "2D range sum" | 2D prefix sum (inclusion-exclusion) |

<br>

## FAANG Frequency

Subarray Sum Equals K alone accounts for **~5% of Meta interviews**. The prefix sum + hash map combo is a must-know pattern.

<br>
