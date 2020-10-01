class Solution {
public:
    vector<string> split(string str)
    {
        vector<string>arr;
        int n=str.size();
        if(n==0)
            return arr;
        int i=0;
        while(str[i]==' ')i++;
        while(str[n-1]==' ')n--;
        string sm;
        for(;i<n;i++)
        {
            if(str[i]==' ')
            {
                arr.push_back(sm);
                sm="";
                while(str[i]==' ')i++;
            }
            sm+=str[i];
        }
        if(sm.size()>0 && sm[0]!=' ')
            arr.push_back(sm);
        return arr;
    }
    bool wordPattern(string pattern, string s) {
        vector<string>arr = split(s);
        unordered_map<char,string>mp;
        set<string>st;
        if(arr.size()!=pattern.size())
            return false;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=arr[i])
                return false;
            if(st.find(arr[i])!=st.end() && (mp.find(pattern[i])==mp.end() || mp[pattern[i]]!=arr[i]))
                    return false;
            else
            {
                mp[pattern[i]]=arr[i];
                st.insert(arr[i]);
            }
        }
        return true;
    }
};