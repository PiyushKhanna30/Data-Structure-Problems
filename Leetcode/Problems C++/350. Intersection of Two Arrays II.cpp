/*

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.size()==0 || nums2.size()==0)return ans;
        unordered_map<int,int>mp;
        for(int num : nums1)
            mp[num]+=1;
        for(int num: nums2)
        {
            if(mp.find(num)!=mp.end() && mp[num]>0)
            {
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};
//Memory O(n)
//Space O(n)

*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.size()==0 || nums2.size()==0)return ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i1=0,i2=0;
        while(i1<nums1.size() && i2<nums2.size())
        {
            if(nums1[i1]==nums2[i2])
            {
                ans.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1]>nums2[i2])
            {
                i2++;
            }
            else
            {
                i1++;
            }
        }
        return ans;
    }
};
//Memory O(nlogn)
//Space O(1)