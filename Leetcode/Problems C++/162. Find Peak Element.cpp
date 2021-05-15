class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0;
        int end = nums.size();
        if(end<=1)return 0;
        end-=1;
        
        if(nums[beg]>nums[beg+1])return beg;
        if(nums[end]>nums[end-1])return end;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            int next = mid+1;
            int prev = mid-1;
            if(nums[mid]>nums[next] && nums[mid]>nums[prev])
                return mid;
            else if(nums[mid]<nums[next])
            {
                beg=mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return -1;
        
    }
};