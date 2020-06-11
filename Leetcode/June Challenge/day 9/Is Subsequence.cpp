class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size()<s.size())
            return false;
        if (s.size()==0)
            return true;
        int j=0; 
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if (s.size()==j)
                    return true;
            }
        }
        return false;
    }
};