class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0;
        int v=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='U')
            {
                v+=1;
            }
            else if(moves[i]=='D')
            {
                v-=1;
            }
            else if(moves[i]=='R')
            {
                h+=1;
            }
            else if(moves[i]=='L')
            {
                h-=1;
            }
        }
        if(h==0 && v==0)
            return true;
        return false;
    }
};