class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>result;
        vector<int>minRows(rows,-1);
        vector<int>maxCols(cols,-1);
        
        //Iterating row wise and put min of that row in minRows
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(minRows[i]==-1 || minRows[i]>matrix[i][j])
                {
                    minRows[i] = matrix[i][j];
                }
            }
        }
        
        //Iterating column wise and put max of that column in maxCols
        for(int i=0;i<cols;i++)
        {
            for(int j=0;j<rows;j++)
            {
                if(maxCols[i]==-1 || maxCols[i]<matrix[j][i])
                {
                    maxCols[i] = matrix[j][i];
                }
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]==minRows[i] && matrix[i][j]==maxCols[j])
                {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};