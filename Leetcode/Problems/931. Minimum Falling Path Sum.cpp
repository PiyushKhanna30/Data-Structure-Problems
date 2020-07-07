class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size();
        if(m==0)
            return 0;
        if(m==1)
            return A[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    A[i][j]+=min(A[i-1][j],A[i-1][j+1]);
                }
                else if(j==m-1)
                {
                    A[i][j]+=min(A[i-1][j-1],A[i-1][j]);
                }
                else
                {
                    A[i][j]+=min(A[i-1][j-1],min(A[i-1][j],A[i-1][j+1]));
                } 
                // cout<<A[i][j]<<" ";
            }
            // cout<<endl;
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,A[m-1][i]);
        }
        return ans;
    }
};