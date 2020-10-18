class Solution {
public:
    string removeDuplicates(string s, int k) {
        pair<char,int>p=make_pair('*',0);
        stack<pair<char,int>>st;
        st.push(p);
        for(int i=0;i<s.size();i++)
        {
            if(st.top().first == s[i])
            {
                if(st.top().second+1 == k)
                {
                    st.pop();
                }
                else
                {
                    p = st.top();
                    st.pop();
                    p.second+=1;
                    st.push(p);
                }
            }
            else
            {
                p = make_pair(s[i],1);
                st.push(p);
            }
        }
        string result;
        while(!st.empty())
        {
            p = st.top();
            st.pop();
            int count = p.second;
            while(count--)
                result = p.first + result;
        }
        return result;
        
    }
};