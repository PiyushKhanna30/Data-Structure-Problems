class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a = b+a;
                st.push(a);
            }
            else if(tokens[i]=="-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a = b-a;
                st.push(a);
            }
            else if(tokens[i]=="/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a = b/a;
                st.push(a);
            }
            else if(tokens[i]=="*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a = b*a;
                st.push(a);
            }
            else
            {
                int a = stoi(tokens[i]);
                st.push(a);
            }
        }
        return st.top();
    }
};