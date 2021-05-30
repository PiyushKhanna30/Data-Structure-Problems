class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count =0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]+=1;
            if(mp[nums[i]]>1)
                count+=mp[nums[i]]-1;
        }
        return count;
    }
};