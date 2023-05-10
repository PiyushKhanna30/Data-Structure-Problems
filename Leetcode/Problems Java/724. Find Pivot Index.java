class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        int leftSum = 0;
        for(int num : nums)
            sum += num;
        
        for(int pivot = 0; pivot<nums.length; pivot++){
            if(leftSum == sum - leftSum - nums[pivot])return pivot;
            leftSum += nums[pivot];
        }
        return -1;
    }
}
