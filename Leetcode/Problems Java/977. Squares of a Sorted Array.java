class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length, l = 0, r = nums.length-1, k = r;
        int[] result = new int[n];
        while(l<=r){
            int lsq = nums[l]*nums[l];
            int rsq = nums[r]*nums[r];
            if(lsq>rsq){
                result[k] = lsq;
                k--;
                l++;
            }
            else{
                result[k] = rsq;
                k--;
                r--;
            }
        }
        return result;
    }
}
