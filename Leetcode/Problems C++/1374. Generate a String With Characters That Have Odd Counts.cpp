class Solution {
public:
    string generateTheString(int n) {
        string ans;
        int x=97;
        if(n%2!=0)
        {
            char c=x;
            int j=n;
            while(j--)
                ans+=c;
        }
        else
        {
            char c=x;
            int j=n-1;
            while(j--)
                ans+=c;
            x++;
            c=x;
            ans+=c;
        }
        
        return ans;
    }
};