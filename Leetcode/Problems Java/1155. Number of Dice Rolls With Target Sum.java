class Solution {
    int mod = (int)Math.pow(10,9)+7;
    private int findways(int d,int f,int target,int[][] memo){
        if(target==0 && d==0) return 1;
        if(d==0) return 0;
        if(memo[d][target]!=-1) return memo[d][target];
        int temp = 0;
        for(int i=f;i>0;i--){
            if(target-i<0) continue;
             temp = (temp%mod+findways(d-1,f,target-i,memo)%mod)%mod;
        }
        return memo[d][target] =  temp; 
    }
    public int numRollsToTarget(int d, int f, int target) {
         int[][] memo = new int[d+1][target+1];
         for(int[] i:memo) Arrays.fill(i,-1);
           
         int ans = findways(d,f,target,memo);
         return ans;
    }
}
