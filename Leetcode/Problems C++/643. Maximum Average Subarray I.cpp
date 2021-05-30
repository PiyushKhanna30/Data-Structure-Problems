class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int index=0;
        double temp,max_avg = 0;
        for(int i=0;i<k;i++)
        {
            max_avg+=nums[i];
        }
        temp = max_avg;
        for(int i=k;i<nums.size();i++)
        {
            temp -= nums[index++];
            temp +=nums[i];
            max_avg = max(max_avg,temp);
        }
        max_avg /= k; 
        return max_avg;
    }
};