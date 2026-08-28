class Solution {
public:
    int find(int i, vector<int> &nums) {
        int n = nums.size();

        if(i == n - 1) return 0;

        int maxProfit = 0;

        for(int j = i + 1; j < n; j++) {
            int profit = 0;

            if(nums[j] > nums[i]) {
                profit = nums[j] - nums[i] + find(j + 1, nums);
            }

            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
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

        return find(0, prices);
    }
};