class Solution {
public:
    bool isValid(vector<int>&nums, int mid,int m)
    {
        int k=m,sum=0;
        for(int num : nums)
        {
            if(sum+num <= mid)
            {
                sum+=num;
            }
            else
            {
                sum=num;
                k--;
                if(k==0)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        if(m>nums.size())return -1;
        int maxElement = INT_MIN;
        int result = -1;
        int sum = 0;
        
        for(int num:nums)
        {
            maxElement = max(maxElement,num);
            sum+=num;
        }
        
        int beg = maxElement;
        int end = sum;
        
        while(beg<=end)
        {
            int mid = beg + (end-beg)/2 ;
            if(isValid(nums,mid,m))
            {
                result = mid;
                end = mid-1;
            }
            else
            {
                beg = mid+1;
            }
        }
        return result;
    }
};