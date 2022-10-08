class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length - 1; i++) {
            int j = i + 1;
            int k = nums.length - 1;


            while (j < k) {
                int curr = nums[i] + nums[j] + nums[k];

                if (curr == target) return target;

                else if (curr < target)
                    j = j + 1;

                else
                    k = k - 1;

                if (Math.abs(target - curr) < Math.abs(target - ans) || ans == Integer.MIN_VALUE)
                    ans = curr;
            }
        }
        return ans;
    }
}
