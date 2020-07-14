class Solution {
public:
    int balancedStringSplit(string s) {
        int c=0;
        int ans=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='R')
            {
                c+=1;
            }
            else if(s[i]=='L')
            {
                c-=1;
            }
            if(c==0)
            {
                ans+=1;
            }
        }
        return ans;
    }
};