class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_index=0 ;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > nums[max_index])
                max_index = i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i != max_index && nums[max_index] < nums[i]*2)
                return -1;
        }
        return max_index;
    }
};
/*
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        int ans=nums[0],prev,ans_index=0;
        for(int i=1;i<nums.size();i++)
        {
            if(ans != -1)
            {
                if(ans < nums[i]*2)
                {
                    prev = ans*2;
                    ans = -1;
                    ans_index = -1;
                }
            }
            if(ans == -1)
            {
                if(nums[i] >= prev)
                {
                    ans = nums[i];
                    ans_index = i;
                }
            }
        }
        return ans_index;
    }
};
*/