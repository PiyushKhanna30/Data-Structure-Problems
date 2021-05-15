class Solution {
public:
    bool check(vector<vector<char>>& board,char c,int x,int y,int n)
    {
        for(int i=x+1;i<n;i++) // check  column
        {
            if( board[i][y] == c)
                return false;
        }
        for(int j=y+1;j<n;j++) // check row
        {
            if( board[x][j] == c)
                return false;
        }
        for(int i = (x/3)*3;i<(x/3)*3 + 3;i++) //check 3x3 box in which it lies
        {
            for(int j=(y/3)*3;j<(y/3)*3 + 3;j++)
            {
                if(i==x && y==j)continue;
                if(board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    if(check(board,board[i][j],i,j,n) == false)
                        return false;
                }
            }
        }
        return true;
    }
};