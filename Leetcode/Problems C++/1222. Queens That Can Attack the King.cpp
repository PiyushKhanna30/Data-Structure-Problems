class Solution {
public:
    void help(vector<vector<bool>>&bd,int x,int y,int dirx,int diry,vector<vector<int>>& queens)
    {
        if(x>=8 || y>=8 || x<0 || y<0)
            return;
        if(bd[x][y]==true)
        {
            
            vector<int>sm={x,y};
            queens.push_back(sm);       //found
            return; 
        }
        help(bd,x+dirx,y+diry,dirx,diry,queens);
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<bool>>bd(8,vector<bool>(8,false));
        for(int i=0;i<queens.size();i++)
            bd[queens[i][0]][queens[i][1]]=true;
        queens.clear();
        
        help(bd,king[0],king[1],1,0,queens);
        help(bd,king[0],king[1],-1,0,queens);
        help(bd,king[0],king[1],0,1,queens);
        help(bd,king[0],king[1],0,-1,queens);
        help(bd,king[0],king[1],1,1,queens);
        help(bd,king[0],king[1],1,-1,queens);
        help(bd,king[0],king[1],-1,1,queens);
        help(bd,king[0],king[1],-1,-1,queens);
        return queens;
    }
};