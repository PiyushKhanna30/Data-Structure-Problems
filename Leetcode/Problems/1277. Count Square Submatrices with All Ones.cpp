class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
        {
            return 0;
        }
        vector<vector<int>>dp=matrix;
        
        //  |0|1|...
        //  |1|1|...
        //  see here above 3 of 1's and none for other
        
        //  |1|1|...
        //  |1|1|...     
        //  see here above 4 of 1's and 1 for 2's
        //  |1|1|...
        //  |1|2|...
        //  min(a[i-1][j],a[i-1][j-1],a[i][j-1])+a[i][j]
        //followed by counting each
        
        // NOW SUPPOSE
        //  EXAMPLE      BY SOLUTION      ACTUAL
        //  |1|1|1|      |1|1|1|          |1|1|1|
        //  |1|1|1| ===> |1|2|2|          |1|2|2|
        //  |1|1|0|      |1|2|2|          |1|2|0|
        //                ans 13          actual ans=11
        // BUT IT IS WRONG so perform min(a[i-1][j],a[i-1][j-1],a[i][j-1])+a[i][j] only when 
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                if(dp[i][j]!=0)
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+dp[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};