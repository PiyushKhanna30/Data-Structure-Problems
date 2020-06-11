bool myfxn(vector<int>a,vector<int>b)
{
    return (abs(a[0]-a[1])>abs(b[0]-b[1]));
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),myfxn);
        int ans=0;
        int a=costs.size()/2;
        int b=a;
        for(int i=0;i<costs.size();i++)
        {
            if(a>0 && b>0)
            {
                if(costs[i][0]<costs[i][1])
                {
                    ans+=costs[i][0];
                    a-=1;
                }
                else
                {
                    ans+=costs[i][1];
                    b-=1;
                }
            }
            else if(a>0)
            {
                ans+=costs[i][0];
                a-=1;
            }
            else
            {
                ans+=costs[i][1];
                b-=1;
            }
            
        }
        return ans;
    }
};