class Solution {
    //TimeO(n) SpaceO(n)
    public int maximumGap(int[] nums) {
        int n = nums.length;
        if(n<2)return 0;
        
        int minNum = Integer.MAX_VALUE;
        int maxNum = Integer.MIN_VALUE;
        
        for(int num:nums){
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }
        int intervals = (int)Math.ceil((maxNum - minNum + 0.0) / (n-1));
        
        int minBucket[] = new int[n-1];
        int maxBucket[] = new int[n-1];
        
        Arrays.fill(minBucket, Integer.MAX_VALUE);
        Arrays.fill(maxBucket, -1);
        
        for(int num:nums){
            if(num == minNum || num == maxNum)continue;
            int bucketIndex = (num-minNum)/intervals;
            minBucket[bucketIndex] = Math.min(minBucket[bucketIndex], num);
            maxBucket[bucketIndex] = Math.max(maxBucket[bucketIndex], num);
        }
        
        int ans = 0;
        
        int prev = minNum;
        for(int i=0;i<n-1;i++){
            if(minBucket[i]==Integer.MAX_VALUE)continue;
            ans = Math.max(ans, minBucket[i]-prev);
            prev = maxBucket[i];
        }
        ans = Math.max(ans, maxNum-prev);
        return ans;
    }
    
    //O(n*log(n))
    // public int maximumGap(int[] nums) {
    //     if(nums.length<2)return 0;
    //     Arrays.sort(nums);
    //     int ans = Integer.MIN_VALUE;
    //     for(int i=0;i<nums.length-1;i++){
    //         ans = Math.max(ans, nums[i+1]-nums[i]);
    //     }
    //     return ans;
    // }
}
