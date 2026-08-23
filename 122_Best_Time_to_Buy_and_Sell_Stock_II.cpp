class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int minCost = prices[0];
        int maxCost = prices[0];

        for(int i = 1; i < n; i++) {
            int currentCost = prices[i];
            
            if(currentCost > maxCost) {
                maxCost = currentCost;
            }
            else if(currentCost < maxCost) {
                maxProfit += (maxCost - minCost);
                minCost = currentCost;
                maxCost = currentCost;
            }
        }

        return maxProfit;
    }
};