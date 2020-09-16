// class Solution {
// public:
//     int numTrees(int n) {
//         vector<int> dp(n+3,0);
//         dp[0]=1;
//         dp[1]=1;
//         dp[2]=2;
//         for(int i=3;i<=n;i++)
//         {
//             for(int j=1;j<=i;j++)
//             {
//                 dp[i]+=(dp[j-1]*dp[i-j]);
//             }
//         }
//         return dp[n];
//     }
// };
class Solution {
public:
    int numTrees(int n) {
        if(n<=2)
            return n;
        vector<int>catalan(n+1);
        catalan[0]=1;
        catalan[1]=1;
        catalan[2]=2;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                catalan[i]+=catalan[j]*catalan[i-1-j];
            }
        }
        return catalan[n];
        
    }
};