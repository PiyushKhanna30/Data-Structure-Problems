class Solution {
public:
    int findArea(vector<vector<int>>& grid, int nx,int ny, int x,int y)
    {
        if(x<0 || y<0 || x>=nx || y>=ny)
            return 0;
        if(grid[x][y]==0)
            return 0;
        grid[x][y]=0;
        return 1+findArea(grid,nx,ny,x-1,y)+findArea(grid,nx,ny,x+1,y)+findArea(grid,nx,ny,x,y+1)+findArea(grid,nx,ny,x,y-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area= 0;
        int nx= grid.size();
        int ny= grid[0].size();
        for(int i=0;i<nx;i++)   //NOT from 0 as [[1]]
        {
            for(int j=0;j<ny;j++)
            {
                if(grid[i][j]==1)
                {
                    max_area = max(max_area,findArea(grid,nx,ny,i,j));
                }
            }
        }
        return max_area;
    }
};