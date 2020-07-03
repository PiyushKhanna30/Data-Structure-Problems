class Solution {
public:
    void findSubsets(int index,vector<int>&nums,vector<int>&small_subset,vector<vector<int>>&ans_subsets)
    {
        ans_subsets.push_back(small_subset);
        for(int i=index;i<nums.size();i++)
        {
            small_subset.push_back(nums[i]);
            findSubsets(i+1,nums,small_subset,ans_subsets);
            small_subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans_subsets;
        int index=0;
        vector<int>small_subset;
        findSubsets(index,nums,small_subset,ans_subsets);
        return ans_subsets;
    }
};

//Time Complexity: O(2 ^ n).

//Space Complexity: O(n).