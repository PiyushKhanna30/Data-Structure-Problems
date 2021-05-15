class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int d30=i,d7=i;
            while(d30<n && days[d30]<days[i]+30)
                d30+=1;
            while(d7<n && days[d7]<days[i]+7)
                d7+=1;
            dp[i] = min(costs[0]+dp[i+1],min(costs[1]+dp[d7],costs[2]+dp[d30]));
        }
        return dp[0];
    }
};