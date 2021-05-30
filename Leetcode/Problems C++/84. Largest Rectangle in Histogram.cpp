class Solution {
public:
    void print(vector<int>&arr)
    {
        for(int x:arr)
            cout<<x<<" ";
        cout<<endl;
    }
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0)
            return 0;
        vector<int>justMinLeft(heights.size());
        vector<int>justMinRight(heights.size());
        
        stack<int>st,st2;
        //Left
        justMinLeft[0]=-1;
        st.push(0);
        for(int i=1;i<heights.size();i++)
        {
            if(heights[st.top()] < heights[i])
            {
                justMinLeft[i] = st.top();
            }
            else
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                if(!st.empty())
                    justMinLeft[i] = st.top();
                else
                    justMinLeft[i] = -1;
            }
            st.push(i);    
        }
        
        //right
        justMinRight[heights.size()-1]=heights.size();
        st2.push(heights.size()-1);
        for(int i = heights.size()-2;i>=0;i--)
        {
            if(heights[st2.top()] < heights[i])
                justMinRight[i]=st2.top();
            else
            {
                while(!st2.empty() && heights[st2.top()]>=heights[i])
                    st2.pop();
                if(!st2.empty())
                    justMinRight[i] = st2.top();
                else
                    justMinRight[i] = heights.size();
            }
            st2.push(i);
        }
        // print(justMinLeft);
        // print(justMinRight);
        int rect =0;
        for(int i=0;i<heights.size();i++)
        {
            int temp = abs(justMinRight[i]-justMinLeft[i])-1;
            temp = temp*heights[i];
            rect = max(rect,temp);
        }
        return rect;
        
    }
};