class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(int i=0;i<paths.size();i++)
        {
            mp[paths[i][0]]=paths[i][1];
        }
        string ans;
        for(auto it:mp)
        {
            if(mp.find(it.second)==mp.end())
            {
                ans=it.second;
                break;
            }
        }
        return ans;
    }
};