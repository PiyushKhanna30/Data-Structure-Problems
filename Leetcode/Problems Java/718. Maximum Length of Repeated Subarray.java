class Solution {
    int ans;

    public int findLength(int[] nums1, int[] nums2) {
        ans = 0;
        //RECURSION
        // findLengthRec(nums1, nums2, 0, 0);

        //MEMOIZATION
        // int[][] dp = new int[nums1.length][nums2.length];
        // for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        // findLengthMem(nums1, nums2, 0, 0, dp);

        //ITERATIVE
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                dp[i + 1][j + 1] = (nums1[i] == nums2[j]) ? 1 + dp[i][j] : 0;
                ans = Math.max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }

    private int findLengthRec(int[] nums1, int[] nums2, int i1, int i2) {
        if (i1 == nums1.length || i2 == nums2.length) return 0;

        int smallAns = 0;
        if (nums1[i1] == nums2[i2])
            smallAns = 1 + findLengthRec(nums1, nums2, i1 + 1, i2 + 1);

        ans = Math.max(ans, smallAns);
        findLengthRec(nums1, nums2, i1, i2 + 1);
        findLengthRec(nums1, nums2, i1 + 1, i2);

        return smallAns;
    }

    private int findLengthMem(int[] nums1, int[] nums2, int i1, int i2, int[][] dp) {
        if (i1 == nums1.length || i2 == nums2.length) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        int smallAns = 0;
        if (nums1[i1] == nums2[i2])
            smallAns = 1 + findLengthMem(nums1, nums2, i1 + 1, i2 + 1, dp);

        ans = Math.max(ans, smallAns);
        findLengthMem(nums1, nums2, i1, i2 + 1, dp);
        findLengthMem(nums1, nums2, i1 + 1, i2, dp);

        return dp[i1][i2] = smallAns;
    }
}
