class Solution {
    public int searchInsert(int[] nums, int target) {
        int beg=0;
        int end=nums.length-1;
        int mid=0;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(target<nums[mid])
            {
                end=mid-1;
                if(end<0 || nums[end]<target )
                {
                    return mid;
                }
            }
            else
            {
                beg=mid+1;
                if(beg>nums.length-1 || nums[beg]>target)
                {
                    return beg;
                }
            }
        }
        return nums.length;
    }
}