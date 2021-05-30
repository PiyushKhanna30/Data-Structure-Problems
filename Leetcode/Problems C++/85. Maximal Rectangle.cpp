class Solution {
public:
    int maxArea(vector<int>&arr,int n)
    {
        stack<int>st;
        vector<int>width(n,0);
        //Left
        width[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            if(arr[st.top()] < arr[i])
            {
                width[i] = st.top();
            }
            else
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                if(!st.empty() && arr[st.top()] < arr[i])
                {
                    width[i] = st.top();
                }
                else
                {
                    width[i] = -1;
                }
            }
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        //Right
        width[n-1] = n-width[n-1]-1;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[st.top()] < arr[i])
            {
                width[i] = st.top()-width[i]-1;
            }
            else
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                if(!st.empty() && arr[st.top()] < arr[i])
                {
                    width[i] = st.top()-width[i]-1;
                }
                else
                {
                    width[i] = n-width[i]-1;
                }
            }
            st.push(i);
        }
        
        //area
        int area = INT_MIN;
        for(int i=0;i<n;i++)
        {
            area = max(area,(width[i]*arr[i]));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m =matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        if(n==0)return 0;
        
        vector<int>sa(n);
        for(int i=0;i<n;i++)
            sa[i]=matrix[0][i]-'0';
        int area = maxArea(sa,n);
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] -'0' == 0)
                    sa[j] = 0;
                else
                    sa[j] += 1;
            }
            area = max(area,maxArea(sa,n));
        }
        return area;
        
    }
};