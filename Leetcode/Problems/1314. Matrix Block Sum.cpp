class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    int find(vector<vector<int>>& mat, int K,int i,int j)
    {
        int value=0;
        int m=mat.size();
        int n=mat[0].size();
        
        for(int r=max(i-K,0);r<=min(i+K,m-1);r++)
        {
            for(int c=max(j-K,0);c<=min(j+K,n-1);c++)
            {
                value+=mat[r][c];
            }
        }
        return value;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if(mat.size()==0)
        {
            return mat;
        }
        
        //Finding m and n
        int m=mat.size();
        int n=mat[0].size();
        
        //Creating answere vector of same size
        vector<vector<int>>answere(m,vector<int>(n));
                                   
        //Filling each cell by looping over it
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                answere[i][j]=find(mat,K,i,j);
            }
        }
        return answere;
    }
};