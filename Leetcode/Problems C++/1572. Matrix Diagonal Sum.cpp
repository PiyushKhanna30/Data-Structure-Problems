class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int result = 0;
        for(int i=0;i<n;i++)
        {
            result+=mat[i][i];          //left to right axis
            result+=mat[n-1-i][i];      //right to left axis
        }
        if(n%2!=0)                      //when odd the middle number added twice
        {
            result -= mat[n/2][n/2];
        }
        return result;
    }
};