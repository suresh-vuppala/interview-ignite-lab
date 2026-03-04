class JumpGame {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // Maximum index we can reach
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // Can't reach this index
            maxReach = max(maxReach, i + nums[i]); // Update max reach
        }
        return true;
    }
};