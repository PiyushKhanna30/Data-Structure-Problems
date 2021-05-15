class Solution {
public:
    static bool comp(pair<char,int>a,pair<char,int>b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]+=1;
        }
        vector<pair<char,int>>vec;
        copy(m.begin(),m.end(),back_inserter(vec));
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<vec.size();i++)
        {
            while(vec[i].second>0)
            {
                ans+=vec[i].first;
                vec[i].second-=1;
            }
        }
        return ans;
    }
};