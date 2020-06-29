class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i:nums)
        {
            m[i]+=1;
        }
        for(auto j:m)
        {
            if(j.second==1)
                return j.first;
        }
        return -1;
    }
};