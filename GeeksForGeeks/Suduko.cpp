#include<bits/stdc++.h>
using namespace std;

vector<int> findEmpty(vector<vector<int>>&board)
{
    vector<int>ans={-1,-1};
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]==0)
            {
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    return ans;
}
bool valid(vector<vector<int>>&board,int x,int y,int num)
{
    ///CHECK FOR num IN ROW
    for(int i=0;i<board[x].size();i++)
    {
        ///IF SAME
        if(board[x][i]==num)
            return false;
    }
    ///CHECK FOR num IN COLUMN
    for(int i=0;i<board.size();i++)
    {
        ///IF SAME
        if(board[i][y]==num)
            return false;
    }
    ///CHECK IF num IN say 9X9 GRID
    int bx=x/3;
    int by=y/3;

    for(int i=bx*3;i<bx*3+3;i++)
    {
        for(int j=by*3;j<by*3+3;j++)
        {
            if(board[i][j]==num)
                return false;
        }
    }
    ///ALL CHECKS PASSED RETURN TRUE
    board[x][y]=num;
    return true;
}
bool solve(vector<vector<int>>&board)
{
    ///SEARCH EMPTY CELL
    vector<int>pts=findEmpty(board);
    int x=pts[0];
    int y=pts[1];
    ///IF NO EMPTY CELL FOUND RETURN TRUE "DONE"
    if(x==-1 || y==-1)
        return true;

    ///ELSE USE NUMBER FROM 1-9 TO FILL USING BACKTRACKING
    for(int i=1;i<=9;i++)
    {
        ///VALIDATE IF FILLING NUMBER IS OK ELSE i++
        if(valid(board,x,y,i))
        {
            board[x][y]=i;
            ///IF OK THEN COMPLETE FULL ROW ELSE BACKTRACK AND UNDO CHANGES
            if(solve(board))
                return true;
            else
                board[x][y]=0;
        }
    }
    ///CANNOT SOLVE SUDUKO
    return false;
}
void printBoard(vector<vector<int>>&board)
{
    for(int i=0;i<board.size();i++)
    {
        if(i%3==0)
        {
            cout<<"- - - - - - - - - "<<endl;
        }
        for(int j=0;j<board[i].size();j++)
        {
            if((j+1)%3==0 && j!=8)
                cout<<board[i][j]<<"|";
            else
                cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"- - - - - - - - - "<<endl<<endl;
}

int main()
{
    vector<vector<int>>board={
    {7,8,0,4,0,0,1,2,0},
    {6,0,0,0,7,5,0,0,9},
    {0,0,0,6,0,1,0,7,8},
    {0,0,7,0,4,0,2,6,0},
    {0,0,1,0,5,0,9,3,0},
    {9,0,4,0,6,0,0,0,5},
    {0,7,0,3,0,0,0,1,2},
    {1,2,0,0,0,7,4,0,0},
    {0,4,9,2,0,6,0,0,7}
    };
    printBoard(board);
    bool solved=solve(board);
    if(solved)
        printBoard(board);
}
