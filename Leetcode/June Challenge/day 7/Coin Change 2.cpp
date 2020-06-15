class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector <int>>ans(coins.size()+1,vector<int>(amount+1));
        for(int i=0;i<coins.size()+1;i++)
        {
            ans[i][0]=1;
        }
        for(int i=1;i<amount+1;i++)
        {
            ans[0][i]=0;
        }
        for(int i=1;i<coins.size()+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                ans[i][j]=ans[i-1][j];
                if(j-coins[i-1]>=0)
                    ans[i][j]+=ans[i][j-coins[i-1]];
            }
        }
        return ans[coins.size()][amount];
        
    }
};