class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();//size of array
        vector<int>ans(n,1);//creating new array to store result
        
        //multiply left results ans put into ans for index i
        ans[0]=1;           
        for(int i=1;i<n;i++)
            ans[i] = ans[i-1]*nums[i-1];
        
        //multiplying for right part of index i,NOTE n-1 already done
        int hr = nums[n-1];//multiply this with n-2 and keep on doing this
        
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = ans[i]*hr;
            hr = hr*nums[i];
        }
        return ans;
    }
};