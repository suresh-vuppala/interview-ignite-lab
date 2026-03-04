class JumpGameII {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Track farthest reachable
            if (i == currentEnd) { // Reached end of current jump
                jumps++; // Make next jump
                currentEnd = farthest; // Update jump boundary
            }
        }
        return jumps;
    }
};