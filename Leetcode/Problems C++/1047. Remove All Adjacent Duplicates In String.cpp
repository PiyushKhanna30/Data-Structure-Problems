class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>st;
        for(int i=0;i<S.size();i++)
        {
            if(!st.empty() && st.top() == S[i])
                st.pop();
            else
                st.push(S[i]);
        }
        string result;
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};