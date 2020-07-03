class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int buy=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(buy>prices[i])
                buy=prices[i];
            else if(profit<prices[i]-buy)
                profit=prices[i]-buy;
        }
        return profit;
    }
};