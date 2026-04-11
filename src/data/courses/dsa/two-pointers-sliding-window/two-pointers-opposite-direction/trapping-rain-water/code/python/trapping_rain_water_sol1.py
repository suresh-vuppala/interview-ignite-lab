class Solution:
    def trap(self, height):
        water = 0
        for i in range(1, len(height)-1):
            max_l = max(height[:i+1])
            max_r = max(height[i:])
            water += min(max_l, max_r) - height[i]
        return water