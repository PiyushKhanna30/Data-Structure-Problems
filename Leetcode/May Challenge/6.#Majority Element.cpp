/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
**/
class Solution {

public:
    Solution()
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int count=1,max_index=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[max_index]==nums[i])
                count+=1;
            else
            {
                count-=1;
                if(count==0)
                {
                    max_index=i;
                    count=1;
                }
            }
        }
        return nums[max_index];
    }
};
