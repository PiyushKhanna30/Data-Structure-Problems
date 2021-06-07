class Solution {
    public int minCostClimbingStairs(int[] cost) {
        // return Math.min(recursive(cost, cost.length-1), recursive(cost, cost.length-2));
        // int[] dp = new int[cost.length];
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // return Math.min(memo(cost, cost.length-1, dp),memo(cost, cost.length-2, dp));
        return dpBU(cost);
    }
    
    //recursive
    private int recursive(int[] cost, int index){
        if(index<0)return 0;
        return cost[index]+Math.min(recursive(cost,index-1),recursive(cost,index-2));
    }

    //recursive + memoization
    private int memo(int[] cost, int index, int[]dp){
        if(index<0)return 0;
        if(dp[index]!=0)return dp[index];
        dp[index] = cost[index]+Math.min(recursive(cost,index-1),recursive(cost,index-2));
        return dp[index];
    }
    
    
    private int dpBU(int[] cost){
        for(int i=2;i<cost.length;i++){
            cost[i] += Math.min(cost[i-1],cost[i-2]);
        }
        return cost[cost.length-1]<cost[cost.length-2]?cost[cost.length-1]:cost[cost.length-2];
    }
}
