int max(int a,int b)
{
    return a>b?a:b;
}
class Solution {
public:
    int scoreOfParentheses(string S) {
        int left =0,ans=0;;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')
                left++;
            else
            {
                left--;
                if(S[i-1]=='(')
                    ans+= max(1,pow(2,left));
            }
        }
        return ans;
    }
};