class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        return (int)(getMaxLength(h, horizontalCuts)*getMaxLength(w, verticalCuts) % 1000000007);
    }
    
    private long getMaxLength(int n, int[] nums){
        Arrays.sort(nums);
//         Handling 1st and last length case
        int maxLen = Math.max(nums[0]-0, n-nums[nums.length-1]);
        int prev = nums[0];
        for(int i=1;i<nums.length;i++){
            maxLen = Math.max(maxLen, nums[i]-prev);
            prev = nums[i];
        }
        return maxLen;
    }
}
