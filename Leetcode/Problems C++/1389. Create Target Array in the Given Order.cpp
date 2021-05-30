class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>result(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            if(result[index[i]]!=-1)
            {
                for(int j=result.size()-2;j>=index[i];j--)
                {
                    result[j+1]=result[j];
                }
            }
            result[index[i]] = nums[i];
        }
        return result;
    }
};