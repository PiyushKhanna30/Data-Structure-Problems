class Solution {
public:
    void dfs(vector<vector<char>>&board,int i,int j,char prev,char replacement)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return;
        if(board[i][j]!=prev)
            return;
        board[i][j]=replacement;
        dfs(board,i+1,j,prev,replacement);
        dfs(board,i,j+1,prev,replacement);
        dfs(board,i,j-1,prev,replacement);
        dfs(board,i-1,j,prev,replacement);
    }
    void solve(vector<vector<char>>& board) {
        int N=board.size();
        if(N<=2)
            return;
        int M=board[0].size();
        if(M<=2)
            return;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='-';
            }
        }
        for(int i=0;i<M;i++)
        {
            if (board[0][i]=='-')
                dfs(board,0,i,'-','O');
        }
        for(int i=0;i<N;i++)
        {
            if (board[i][0]=='-')
                dfs(board,i,0,'-','O');
        }
        for(int i=0;i<M;i++)
        {
            if (board[N-1][i]=='-')
                dfs(board,N-1,i,'-','O');
        }
        for(int i=0;i<N;i++)
        {
            if (board[i][M-1]=='-')
                dfs(board,i,M-1,'-','O');
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(board[i][j]=='-')
                    board[i][j]='X';
            }
        }
    }
};