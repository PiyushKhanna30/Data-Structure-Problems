class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        if(prices.length<2)return ans;
        
        int buyPrice = prices[0];
        for(int i = 1; i<prices.length; i++){
            if(prices[i] < buyPrice)
                buyPrice  = prices[i];
            else
                ans = Math.max(ans, prices[i]-buyPrice);
        }
        return ans;
    }
}

/**TLE
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int res[] = new int[n];
        Arrays.fill(res, 0);
        res[n - 1] = 0;
        for (int i = 0; i <= n - 2; i++)
            for (int j = i + 1; j < n; j++)
                if (prices[i] < prices[j] && res[i] < prices[j] - prices[i])
                    res[i] = prices[j] - prices[i];

        int ans = Integer.MIN_VALUE;
        
        for (int num : res)
            ans = Math.max(ans, num);
        
        return ans;
    }
}
**/
