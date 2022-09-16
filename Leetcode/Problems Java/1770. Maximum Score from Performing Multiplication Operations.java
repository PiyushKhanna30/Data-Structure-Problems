class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        int[][] dp = new int[multipliers.length][multipliers.length];
        return maximumScoreRec(nums, multipliers, 0, 0, nums.length - 1, dp);
    }

    public int maximumScoreRec(int[] nums, int[] multipliers, int i, int l, int r, int[][] dp) {
        if (i == multipliers.length) return 0;
        if (dp[i][l] != 0) return dp[i][l];

        int left = (nums[l] * multipliers[i]) + maximumScoreRec(nums, multipliers, i + 1, l + 1, r, dp);
        int right = (nums[r] * multipliers[i]) + maximumScoreRec(nums, multipliers, i + 1, l, r - 1, dp);
        dp[i][l] = Math.max(left, right);
        return dp[i][l];
    }
}
