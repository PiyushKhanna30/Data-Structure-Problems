class Node
{
    public:
    int x, y,time;
    Node(int x,int y,int time)
    {
        this->x=x;
        this->y=y;
        this->time=time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        if(m==0||n==0)
            return ans;
        queue<Node *>que;
        int good_oranges=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    que.push(new Node(i,j,0));
                }
                if(grid[i][j]==1)
                {
                    good_oranges+=1;
                }
            }
        }
        
        while(!que.empty())
        {
            Node * temp = que.front();
            que.pop();
            int i=temp->x;
            int j=temp->y;
            int time = temp->time;
            bool check=false;
            if(i>0 && grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                que.push(new Node(i-1,j,time+1));
                good_oranges--;
                check=true;
            }
            if(i<m-1 && grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                que.push(new Node(i+1,j,time+1));
                good_oranges--;
                check=true;
            }
            if(j>0 && grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                que.push(new Node(i,j-1,time+1));
                good_oranges--;
                check=true;
            }
            if(j<n-1 && grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                que.push(new Node(i,j+1,time+1));
                good_oranges--;
                check=true;
            }
            if(check)
                ans=max(ans,time+1);
        }
        if(good_oranges==0)
            return ans;
        return -1;
        
    }
};