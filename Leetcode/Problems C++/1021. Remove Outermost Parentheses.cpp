class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.size()==0 || S[0]!='(')
            return "";
        string result;
        stack<char>st;
        for(int i=0;i<S.size()-1;i++)
        {
            if(S[i] == '(')
            {
                if(!st.empty())
                    result+=S[i];
                st.push('(');
            }
            else
            {
                if(st.size()>1)
                {
                    result+=')';
                }
                st.pop();
            }
        }
        return result;
    }
};