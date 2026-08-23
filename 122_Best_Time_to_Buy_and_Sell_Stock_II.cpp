class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int currentCost = 0;
        int minCost = prices[0];
        int profit = 0;

        for(int i = 1; i < n; i++) {
            currentCost = prices[i];
            if(currentCost < minCost) {
                minCost = currentCost;
            }
            else {
                maxProfit = max(maxProfit, currentCost - minCost);
                profit += maxProfit;
            }
        }

        return profit;
    }
};