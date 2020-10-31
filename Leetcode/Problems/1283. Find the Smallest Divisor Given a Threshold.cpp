class Solution {
public:
    bool isValid(vector<int>&nums, int mid,int threshold)
    {
        int sum=0;
        for(int num : nums)
        {
            sum+= num%mid==0 ? num/mid:num/mid+1;
            if(sum>threshold)return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int beg = 1;
        int end = INT_MIN;
        for(int num : nums)
        {
            end = max(end,num);
        }
        
        int result = -1;
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2;
            if(isValid(nums,mid,threshold))
            {
                result = mid;
                end=mid-1;
            }
            else
            {
                beg = mid+1;
            }
        }
        return result;
    }
};