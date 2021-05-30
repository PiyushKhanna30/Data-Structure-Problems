class Solution {
public:
    int find(vector<vector<int>>& board,int x,int y)
    {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]==0 || board[x][y]==2)
            return 0;
        return 1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                    int a = find(board,i-1,j-1)+find(board,i-1,j)+
                        find(board,i-1,j+1)+
                        find(board,i,j-1)+find(board,i,j+1)+find(board,i+1,j-1)+find(board,i+1,j)+find(board,i+1,j+1);
                    if(board[i][j]==0 && a==3)
                        board[i][j]=2;
                    else if(board[i][j]==1 && a!=2 && a!=3)
                        board[i][j]=-1;
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]== -1)
                {
                    
                        board[i][j]=0;
                }
                else if(board[i][j]==2)
                {
                    board[i][j]=1;
                }
            }
        }
    }
};