class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>st;
        vector<string>result;
        int k =0;
        for(int i=1;i<=n;i++)
        {
            st.push(i);
            result.push_back("Push");
            if(st.top()!=target[k])
            {
                st.pop();
                result.push_back("Pop");
            }
            else
            {
                k++;
                if (k>=target.size())
                    break;
            }
        }
        return result;
    }
};