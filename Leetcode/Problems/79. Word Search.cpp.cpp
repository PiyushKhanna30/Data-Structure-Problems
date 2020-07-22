class Solution {
public:
    bool find(vector<vector<char>> &board, string &word,int &x,int &y,int index,int i,int j)
    {
        if(index == word.size())
            return true;
        if(i<0 || i>=x || j<0 || j>=y || board[i][j]=='\0')
            return false;
        if(board[i][j]==word[index])
        {
            char t=board[i][j];
            board[i][j]='\0';
            if(find(board,word,x,y,index+1,i-1,j) || find(board,word,x,y,index+1,i+1,j) || find(board,word,x,y,index+1,i,j-1) || find(board,word,x,y,index+1,i,j+1))
                return true;
            board[i][j]=t;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int x=board.size();
        int y=board[0].size();
        int index=0;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(find(board,word,x,y,index,i,j))
                    return true;
            }
        }
        return false;
    }
};