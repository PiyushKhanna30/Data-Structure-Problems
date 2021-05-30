class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0)return nums1;
        if(nums2.size()==0)
        {
            vector<int>arr(nums1.size(),-1);
            return arr;
        }
        stack<int>st;
        vector<int>r(nums2.size());
        
        r[nums2.size()-1] = -1;
        st.push(nums2[nums2.size()-1]);
        
        for(int i=nums2.size()-2;i>=0;i--)
        {
            if(st.top()>nums2[i])
                r[i]=st.top();
            else
            {
                while(!st.empty() && st.top()<nums2[i])
                    st.pop();
                if(!st.empty() && st.top()>nums2[i])
                    r[i]=st.top();
                else
                    r[i]=-1;
            }
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i] == nums2[j])
                {
                    nums1[i] = r[j];
                    break;
                }
            }
        }
        return nums1;
    }
};