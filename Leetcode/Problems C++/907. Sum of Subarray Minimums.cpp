class Solution {
public:
    vector<int>minArr(vector<int>&A)
    {
        
        vector<int>result(A.size(),1);
        stack<int>st;
        int n = A.size();
        //left
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && A[st.top()]>=A[i])
                st.pop();
            if(!st.empty())
            {
                result[i]=i-st.top();
            }
            else
            {
                result[i]=i+1;
            }
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        //Right
        result[n-1] *= 1;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && A[st.top()]>A[i])
                st.pop();
            if(!st.empty())
            {
                result[i]*= (st.top() - i);
            }
            else
            {
                result[i]*=(n-i);
            }
            st.push(i);
        }
        
        return result;
    }
    int sumSubarrayMins(vector<int>& A) {
        if(A.size()==0)return 0;
        int ans =0;
        vector<int>maxSubs = minArr(A);
        int mod = pow(10,9)+7;
        for(int i=0;i<A.size();i++)
        {   
            // cout<<A[i]<<" "<<maxSubs[i]<<endl;
            ans += (A[i]*maxSubs[i])%mod;
            ans %=mod;
        }
        return ans;
    }
};