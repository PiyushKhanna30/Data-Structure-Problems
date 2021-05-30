class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                int x=m[target-nums[i]];
                ans.push_back(x);
                ans.push_back(i);
                return ans;

            }
            else
            {
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};
