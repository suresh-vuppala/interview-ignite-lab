class JumpGame {
    public boolean canJump(int[] nums) {
        int maxReach = 0; // Maximum index we can reach
        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach) return false; // Can't reach this index
            maxReach = Math.max(maxReach, i + nums[i]); // Update max reach
        }
        return true;
    }
}