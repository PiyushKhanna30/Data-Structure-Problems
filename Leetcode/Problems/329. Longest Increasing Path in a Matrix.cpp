class Solution {
public:
    int findPath(vector<vector<int>>& matrix,vector<vector<int>>& dp,int &x,int &y,int i,int j,int prev)
    {
        if(i<0 || i>=x || j<0 ||j>=y)
            return 0;
        
        if(prev<matrix[i][j])
        {
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int top=findPath(matrix,dp,x,y,i-1,j,matrix[i][j])+1;
            int left=findPath(matrix,dp,x,y,i,j-1,matrix[i][j])+1;
            int right=findPath(matrix,dp,x,y,i,j+1,matrix[i][j])+1;
            int bottom=findPath(matrix,dp,x,y,i+1,j,matrix[i][j])+1;
            dp[i][j]=max(max(top,left),max(right,bottom));
            return dp[i][j];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int x=matrix.size();
        if(x==0)
            return 0;
        int y=matrix[0].size();
        vector<vector<int>>dp(x,vector<int>(y,-1));
        int ans=INT_MIN;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                ans=max(ans,findPath(matrix,dp,x,y,i,j,INT_MIN));
            }
        }
        return ans;
    }
};
/*
1. create dp array and initialize all values as -1.(Not 0 as at some i,j value may be stored as 0)
2.now iterate over every element in matrix and call findPath on the function.
3.Now we check i,j lie inside matrix,else return 0
4.Now we check if this value in matrix is greater than prev element then
    4a.check if dp[i][j] not equal to 0 then return it
    4b.else findPath for this vertex
5 at last if prev is equal or greater then return 0.
Complexity=O(MN)
*/