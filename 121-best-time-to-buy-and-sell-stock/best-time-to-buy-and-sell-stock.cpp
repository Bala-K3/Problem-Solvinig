class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0, maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};