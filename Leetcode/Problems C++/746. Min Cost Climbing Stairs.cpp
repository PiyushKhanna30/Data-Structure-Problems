class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //At every step we have 2 options ie i-1 & i-2 so select min cost and add the current cost in it
        int n=cost.size();
        //put each cost value in dp vector
        vector<int>dp=cost;
        //increment size by 1 of dp that holds answere
        dp.push_back(0);
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+dp[i];
        }
        return dp[n];
    }
};