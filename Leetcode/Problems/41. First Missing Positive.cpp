//We set each number to index-1 if it can be fitted into array. we dont use if as in case 3 4 -1 1  --->   -1 4 3 1   --->   -1 1 3 4 so it can cause error. we need to check if this number has reached its correct position. so we again check 1 -1 3 4 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int i=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return i+1;
    }
};