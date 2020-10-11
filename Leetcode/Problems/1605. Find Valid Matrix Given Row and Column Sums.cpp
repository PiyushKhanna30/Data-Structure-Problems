class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= arr[i][j];
                colSum[j] -= arr[i][j];
            }
        }
        return arr;
    }
};
/*

Explanation:
 rowSum = [3,8], colSum = [4,7]
1.Initialize matrix of size rowSum.size()x colSum.size() with 0's.
	[[0,0]
	 [0,0]]
2.Think greedy.

rowSum  colSum
	[4    7]  
[3]    [[0    0]
[8]	[0    0]]

loop over matrix and fill with min sum of row or col and update them

	[1    7]  
[0]    [[3    0]
[8]	[0    0]] 


	[1    7]  
[0]    [[3    0]
[8]	[0    0]]


	[0    7]  
[0]    [[3    0]
[7]	[1    0]]


	[0    0]  
[0]    [[3    0]
[0]	[1    7]]

return matrix
*/