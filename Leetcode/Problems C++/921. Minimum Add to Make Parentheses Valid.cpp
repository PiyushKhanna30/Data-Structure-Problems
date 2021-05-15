class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0,right =0;
        for(char c:S)
        {
            if(c=='(')
                left+=1;
            else if(left>0)
                left--;
            else
                right++;
        }
        return left+right;
    }
};

// class Solution {
// public:
//     int minAddToMakeValid(string S) {
//         stack<char>st;
//         st.push('*');
//         int result = 0;
//         for(int i=0;i<S.size();i++)
//         {
//             if(S[i]=='(')
//                 st.push('(');
//             else
//             {
//                 if(st.top()=='*')
//                     result+=1;
//                 else
//                     st.pop();
//             }
//         }
//         result+= (st.size()-1);
//         return result;
//     }
// };