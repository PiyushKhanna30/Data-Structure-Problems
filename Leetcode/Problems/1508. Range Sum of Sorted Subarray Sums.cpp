class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>pq;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {   
                sum+=nums[j];
                // cout<<sum<<" ";
                pq.push_back(sum);
            }
        }
        
        int result = 0;
        int mod = pow(10,9)+7;
        sort(pq.begin(),pq.end());
        for(int i=left-1;i<right;i++)
        {
            result+=pq[i];
            result%=mod;
        }
        return result;
    }
};