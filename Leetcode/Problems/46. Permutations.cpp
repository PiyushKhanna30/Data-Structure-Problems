void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
class Solution {
public:
    void findPermutations(vector<int>&nums,vector<vector<int>>&results,int index)
    {
        if(index == nums.size()-1)
        {
            results.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            findPermutations(nums,results,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        findPermutations(nums,results,0);
        return results;
    }
};