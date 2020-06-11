class Solution {
    public void sortColors(int[] nums) 
    {
        int beg=0;
        int end=nums.length-1;
        int index=0;
        while(index<=end && beg<=end)
        {
            if(nums[index]==0)
            {
                nums[index]=nums[beg];
                nums[beg]=0;
                index+=1;
                beg+=1;
            }
            else if(nums[index]==2)
            {
                nums[index]=nums[end];
                nums[end]=2;
                end-=1;
            }
            else
            {
                index++;
            }
        }
    }
}