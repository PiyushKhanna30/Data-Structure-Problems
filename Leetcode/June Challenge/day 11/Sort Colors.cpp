class Solution {
public:
    void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
    void sortColors(vector<int>& nums) 
    {
        int beg=0;
        int end=nums.size()-1;
        int index=0;
        while(index<=end && beg<=end)
        {
            if(nums[index]==0)
            {
                swap(&nums[index++],&nums[beg++]);
            }
            else if(nums[index]==2)
            {
                swap(&nums[index],&nums[end--]);
            }
            else
            {
                index++;
            }
        }
    }
};