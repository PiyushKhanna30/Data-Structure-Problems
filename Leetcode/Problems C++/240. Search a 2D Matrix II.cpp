class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();
        if(m==0)return false;
        int n = matrix[0].size();
        if(n==0)return false;
        
        int i=0,j=n-1;
        while(j>=0 && i<m)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
        
    }
};