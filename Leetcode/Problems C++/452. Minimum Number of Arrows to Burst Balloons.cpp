bool cmp(vector<int>p1,vector<int>p2)
{
    if(p1[0]<p2[0])
        return true;
    return false;
}
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& p) {
        if(p.size()<=1)
            return p.size();
        int a =0;
        sort(p.begin(),p.end(),cmp);
        for(int i=1;i<p.size();i++)
        {
            if(p[i-1][1]>=p[i][0])
            {
                p[i][1] = min(p[i-1][1],p[i][1]);
            }
            else
            {    a+=1;
             // i++;
            }
        }
        return a+1;
    }
};