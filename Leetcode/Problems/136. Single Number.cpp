class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto i : nums)
        {
            ans^=i;            ///Xor : 110^101==011||  2^2==0
        }
        return ans;
    }
};