class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        //Put all elements in map ans there occurences
        for(int num:nums)
            mp[num]+=1;
        
        int ans=0;
        
        //loop over map
        for(auto it :mp)
        {
            //when k=0 find pairs of same number, so we find keys with occurence >1
            if(k==0 && it.second>1)
                ans+=1;
            //else when k!=0 since b-a=k so b-k = a , we try to find a in map , if found increment ans
            else if(k!=0 && mp.find(it.first - k)!=mp.end())
                ans+=1;
        }
        return ans;
    }
};