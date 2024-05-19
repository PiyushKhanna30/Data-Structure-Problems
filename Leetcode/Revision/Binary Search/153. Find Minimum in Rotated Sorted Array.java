class Solution {
    public int findMin(int[] nums) {
        int start = 0;
        int end = nums.length-1;
        int ans = Integer.MAX_VALUE;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[start]<=nums[end]){
                ans = Math.min(nums[start], ans);
                return ans;
            }
            else if(nums[start]<=nums[mid]){
                ans = Math.min(nums[start], ans);
                start = mid + 1;
            }
            else{
                ans = Math.min(nums[mid], ans);
                end = mid-1;
            }
        }
        return ans;
    }
}
// class Solution {
//     public int findMin(int[] nums) {
//         int start = 0;
//         int end = nums.length-1;
        
//         while(start<=end){
//             int mid = start + (end-start)/2;
//             //just left number must be greater than smallest element
//             if(mid>0 && nums[mid-1]>nums[mid])
//                 return nums[mid];
            
//             //check if answere lies in right side by check if cur is highest from both sides
//             if(nums[start]<=nums[mid] && nums[mid]>nums[end]){
//                 start = mid + 1;
//             }
//             else{
//                 end = mid - 1;
//             }
//         }
//         return nums[0];
//     }
// }
