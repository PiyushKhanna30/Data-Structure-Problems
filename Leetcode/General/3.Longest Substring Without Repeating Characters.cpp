class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int ans=0;
        int start=-1;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(start<m[s[i]])
                    start=m[s[i]];
                m[s[i]]=i;
            }
            else
            {
                m[s[i]]=i;
            }
            ans=max(ans,i-start);
        }
        return ans;
    }
};