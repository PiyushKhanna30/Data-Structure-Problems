//METHOD 1 Storing index and sum in map  BUT TIME LIMIT EXCEED
class NumArray {
public:
    map<pair<int,int>,int>mp;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                pair<int,int>p;
                p=make_pair(i,j);
                mp[p]=sum;
            }
        }
    }
    
    int sumRange(int i, int j) {
        pair<int,int>p;
        p=make_pair(i,j);
        return mp[p];
    }
};
//O(n^2)

//METHOD 2 Storing sum in array
/*
eg 
nums = [1,2,3]
sum  = [1,3,6]

sum of index [0,2] ans=sum[2]
sum of index [1,2] ans=sum[2]-sum[0]
sum of index [0,1] ans=sum[1]

*/

class NumArray {
public:
    vector<int>sum;
    NumArray(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x+=nums[i];
            sum.push_back(x);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return sum[j];
        return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */