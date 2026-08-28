class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentCost = prices[0];
        int minCost = prices[0];
        int profit = 0;

        int n = prices.size();

        for(int i = 1; i < n; i++) {
            currentCost = prices[i];

            if(currentCost < minCost) {
                minCost = currentCost;
            }

            profit = max(profit, currentCost - minCost);
        }

        return profit;
    }
};