class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=sum+nums[i];
            sum=max(sum,nums[i]);
            ans=max(sum,ans);
        }
        return ans;
    }
};
//Solving using Kadane's Algorithm