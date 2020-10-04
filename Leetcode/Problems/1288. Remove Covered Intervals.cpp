class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0;i<n-1;i++)
        {
            if(intervals[i][0]==-1)
                continue;
            for(int j=i+1;j<n;j++)
            {
                int a=intervals[i][0];
                int b=intervals[i][1];
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(i==j || intervals[j][0]==-1)
                    continue;
                if(a<=c && d<=b)
                    intervals[j][0]=-1;
                else if(c<=a && b<=d)
                {
                    intervals[i][0]=-1;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0]!= -1)
                ans+=1;
        }
        return ans;
    }
};