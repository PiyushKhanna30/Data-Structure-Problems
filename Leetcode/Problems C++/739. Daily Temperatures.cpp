class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        if(n==0)return T;
        vector<int>result(n,0);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(T[st.top()] > T[i])
            {
                result[i]=st.top()-i;
            }
            else
            {
                while(!st.empty() && T[st.top()]<=T[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    result[i] = st.top()-i;
                }
                else
                {
                    result[i] = 0;
                }
            }
            st.push(i);
        }
        return result;
    }
};

// TLE
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         int n = T.size();
//         vector<int>result(n,0);
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(T[j]>T[i])
//                 {
//                     result[i]=j-i;
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };