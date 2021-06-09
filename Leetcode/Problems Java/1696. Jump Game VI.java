class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        // for(int i=0;i<n-1;i++){
        //     // System.out.print("Index : "+i+" = ");
        //     int max = Integer.MIN_VALUE;
        //     int index = -1;
        //     for(int j=i+1;j<=Math.min(n-1,i+k);j++){
        //         // System.out.print(j+", ");
        //         if(nums[i]+nums[j] > max){
        //             max = nums[i]+nums[j];
        //             index = j;
        //         }
        //     }
        //     // System.out.println();
        //     nums[index] = max;
        //     i = index-1;
        // }
        // // for(int num:nums)System.out.println(num);
        // return nums[n-1];
        
        Queue<Integer>q = new PriorityQueue<>(k, Collections.reverseOrder());
        q.add(nums[0]);
        
        for(int i = 1;i<n;i++){
            
            int num = nums[i];
            int max = q.peek();
            nums[i] = max + num;
            
            if(q.size()==k){
                q.poll();
            }
            
            while(q.isEmpty()==false && q.peek()<nums[i])q.poll();
            
            q.add(nums[i]);
        }
        return nums[n-1];
    }
}
