class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                if(st.empty())
                    s[i]='*';
                //why not push i? consider ))(( this example on second ) it pops first )
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            s[st.top()]='*';
            st.pop();
        }
        string result;
        for(char c:s)
        {
            if(c!='*')result+=c;
        }
        return result;
    }
};