class Solution {
    // public void rotate(int[] nums, int k) {
    //     int n = nums.length;
    //     k %= n;
    //     if(k==0 || (k==1 && n == 1))return;
    //     while(k>0){
    //         k--;
    //         int temp = nums[n-1];
    //         for(int i=n-1;i>=1;i--)
    //             nums[i] = nums[i-1];
    //         nums[0] = temp;
    //     }
    // }
    //TLE O(n*k)

    private void reverse(int[]nums, int l, int r){
        while(l<r){
            int t = nums[l];
            nums[l++] = nums[r];
            nums[r--] = t;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        if(k==0 || (k==1 && n == 1))return;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
}
