class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int s = 1;
        int e = n-2;
        
        while(s<=e){
            int mid = s+(e-s)/2; 
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]){
                return mid;
            }
            else if(nums[mid-1]>nums[mid]){
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
}
