class Solution {
public:
    int findPerimeter(vector<vector<int>>& grid,int &m,int &n,int i,int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
        {
            return 1;
        }
        if (grid[i][j]==1)
        {
            grid[i][j]=-1;
            int top = findPerimeter(grid,m,n,i-1,j);
            int left = findPerimeter(grid,m,n,i,j-1);
            int right = findPerimeter(grid,m,n,i,j+1);
            int bottom = findPerimeter(grid,m,n,i-1,j);
            return top + left + right +bottom;
        }
        return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    perimeter = perimeter + findPerimeter(grid,m,n,i,j);
                }
            }
        }
        return perimeter;
    }
};

/*

1.Iterate grid and where grid[i][j]==1 call findPerimiter.
2.In findPerimeter set boundary cases when i,j out of bounds and when grid[i][j]==0 ie water then count this side in perimeter so return 1
3.if grid[i][j]==1 mark it as -1 ie for visited and explore all adjacent sides and return sum.
4.else return 0

In islandPerimeter I run for loop as if there may be more than 1 islands in matrix.
*/