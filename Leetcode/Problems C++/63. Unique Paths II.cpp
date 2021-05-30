class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int x = obstacleGrid.size();
        int y = obstacleGrid[0].size();
        
        //base conditions check
        if(x==0 || y==0 || obstacleGrid[0][0]==1 || obstacleGrid[x-1][y-1]==1)
            return 0;
        
        //Set 0,0 bit 1 means it can be visited in 1 way
        obstacleGrid[0][0]=1;
        
        //Row 0 from left to right can be visited only if its left is not obstacle. If at pt we encounter obstacle no. of ways to get there are 0 so update it. and fill all elements with element on its left
        for(int i=1;i<y;i++)
        {
            obstacleGrid[0][i] = obstacleGrid[0][i]==0 ? obstacleGrid[0][i-1] :0;
        }
        
        //Similar to top row first column can be visited by element on its top
        for(int i=1;i<x;i++)
        {
            obstacleGrid[i][0] = obstacleGrid[i][0]==0 ? obstacleGrid[i-1][0]:0;
        }
        
        //Beginning from 1,1 we check in how many ways this position can be visted if this place is not an obstacle, else if obstacle then update it to be 0
        for(int i=1;i<x;i++)
        {
            for(int j=1;j<y;j++)
            {
                if(obstacleGrid[i][j]!=1)
                {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
                else
                {           
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[x-1][y-1];
    }
};


/*
0 0 1 0 0   
0 0 0 1 0
0 0 0 0 1   
1 0 0 0 0

After updating 1st row and column
1 1 0 0 0   
1 0 0 1 0
1 0 0 0 1   
0 0 0 0 0

1 1 0 0   0   
1 2 2 0   0
1 3 5 5   0   
0 3 8 13  13


So ans = 13
*/