class Solution {
public:
    static bool c(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),c);
        int cu;
        vector<vector<int>>ans(p.size(),vector<int>(2,-1));
        for(int i=0;i<p.size();i++)
        {
            cu=p[i][1];
            for(int j=0;j<p.size();j++)
            {
                if(cu==0 && ans[j][0]==-1)
                {
                    ans[j][0]=p[i][0];
                    ans[j][1]=p[i][1];
                    break;
                }
                else if(ans[j][0]==-1||ans[j][0]>=p[i][0])
                {
                    cu--;
                }
            }
        }
        return ans;
    }
};