class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]+=1;
        }
        priority_queue<int,vector<int>, greater<int>>pq;
        for(auto i : m)
        {
            pq.push(i.second);
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        for(auto i:m)
        {
            if(i.second>=pq.top())
                ans.push_back(i.first);
        }
        return ans;
        
    }
};
/*
class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]+=1;
        }
        vector<pair<int,int>>vec;
        copy(m.begin(),m.end(),back_inserter(vec));
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<k;i++)
            ans[i]=vec[i].first;
        return ans;
    }
};
*/