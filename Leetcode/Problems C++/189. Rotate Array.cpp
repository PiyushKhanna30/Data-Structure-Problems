class Solution {
public:
    void reverse(vector<int>&nums,int beg,int end)
    {
        end = end-1;
        while(beg<end)
        {
            int temp = nums[beg];
            nums[beg] = nums[end];
            nums[end] =temp;
            beg++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k=k%size;
        if(size<=1 || k==0)
            return;
        
        reverse(nums,0,size);
        reverse(nums,0,k);
        reverse(nums,k,size);
    }
};

/*
Approach 1 : move 1 by 1 for k times. O(n)*k == O(nk)
Approach 2 : extra space. O(n) memory,O(n) space
Approach 3 : reversing O(n)
*/