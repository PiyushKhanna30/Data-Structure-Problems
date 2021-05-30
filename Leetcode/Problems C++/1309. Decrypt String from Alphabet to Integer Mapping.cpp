class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='#')
            {
                char c = (s[i-2]-'0')*10 + (s[i-1]-'0') + 96;
                ans = c + ans;
                i=i-2;
            }
            else
            {
                char c = (s[i]-'0') + 96;
                ans = c + ans;
            }
        }
        return ans;
    }
};
/*
ASCII
0-9 : 48-57
a-z : 97-122
A-Z : 65-90
*/