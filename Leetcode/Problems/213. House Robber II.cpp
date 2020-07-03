class Solution {
public:
    
    int rob_h(vector<int> &nums) {
        if(nums.size()==0)
            return 0;
        int dp[nums.size()+1];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[nums.size()];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<int>a;
        vector<int>b;
        for(int i=0;i<nums.size()-1;i++)
            a.push_back(nums[i]);
        for(int i=1;i<nums.size();i++)
            b.push_back(nums[i]);
        int a1=rob_h(a);
        int b1=rob_h(b);
        return a1>b1?a1:b1;
    }
};