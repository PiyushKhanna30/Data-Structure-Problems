class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(result.size());
            else if(s[i]==')')
            {
                int prevIndex = st.top();
                st.pop();
                reverse(result.begin()+prevIndex,result.end());
            }
            else
            {
                result+=s[i];
            }
        }
        return result;
    }
};
/*
xyz(ab(cd)) == xyzcdba
res=x
res=xy
res=xyz
res=xyz     [3]
res=xyza    [3]
res=xyzab   [3]
res=xyzab   [6,3]
res=xyzabc  [6,3]
res=xyzabcd [6,3]

res=xyabdc  [3]

res=xycdba  []
*/