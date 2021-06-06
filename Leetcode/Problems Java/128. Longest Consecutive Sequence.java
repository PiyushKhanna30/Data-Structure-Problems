class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length <= 1)return nums.length;
        Set<Integer> myNums = new HashSet<>();
        for(int num:nums){
            myNums.add(num);
        }
        int res = 1;
        for(int num:nums){
            if(myNums.contains(num-1)==false && myNums.contains(num+1)==true){
                int count = 2;
                int nextNum = num+2;
                while(myNums.contains(nextNum)){
                    nextNum+=1;
                    count+=1;
                }
                res = Math.max(res, count);
            }
        }
        return res;        
    }
}
