class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string small;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                ans+=small+" ";
                small="";
            }
            else
            {
                small=s[i]+small;
            }
        }
        ans+=small;
        return ans;
    }
};