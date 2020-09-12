class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i]);
            if(nums[index-1] >0)
                nums[index-1] *=(-1);
            else
                ans.push_back(index);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
        
    }
};
/*
Steps
-----
1.iterate array and mark num-1 index as negative.(by this we mark -ve all nums that appear)
2.if for any index we find that already index marked negative hen it is repetating.
3.Now again iterate to find non negative number and push its i+1 and return ans.
*/