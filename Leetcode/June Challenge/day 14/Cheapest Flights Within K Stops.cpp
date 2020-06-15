class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<int>>adj(n,vector<int>(n,-1));
        for(int i=0;i<flights.size();i++)
        {
            for(int j=0;j<flights[i].size();j++)
            {
                adj[flights[i][0]][flights[i][1]]=flights[i][2];
            }
        }
        priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,K+1});
        while(!pq.empty())
        {
            vector<int>t=pq.top();
            pq.pop();
            int d=t[0];
            int s=t[1];
            int k=t[2];
            if(s==dst)
                return d;
            else if(k>0)
            {
                for(int i=0;i<n;i++)
                {
                    if(adj[s][i]==-1)
                        continue;
                    pq.push({d+adj[s][i],i,k-1});

                }
            }
        }
        return -1;
    }
};