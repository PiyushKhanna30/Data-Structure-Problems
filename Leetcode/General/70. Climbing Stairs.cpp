class Solution {
public:
    int climbStairs(int n) {
        int *dp=new int[n+3];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<n+1;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        int ans=dp[n];
        delete []dp;
        return ans;
    }
};