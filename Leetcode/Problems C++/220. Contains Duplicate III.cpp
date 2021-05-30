class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long>s;
        for(int i=0;i<nums.size();i++)
        {
            auto x = s.lower_bound((long)nums[i]-(long)t);
            if(x!=s.end() && abs(*x-(long)nums[i])<=(long)t)
                return true;
            s.insert(nums[i]);
            if(s.size()>k)
                s.erase((long)nums[i-k]);
        }
        return false;
    }
};