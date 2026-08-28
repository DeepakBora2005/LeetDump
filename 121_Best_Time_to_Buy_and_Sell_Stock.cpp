class Solution {
public:
    int find(int i, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();

        if(i == n - 1) return 0;

        if(dp[i] != - 1) return dp[i];

        int maxProfit = 0;

        for(int j = i + 1; j < n; j++) {
            int profit = 0;
            if(nums[j] > nums[i]) {
                profit = nums[j] - nums[i];
            }

            maxProfit = max(profit, maxProfit);
        }

        maxProfit = max(maxProfit, find(i + 1, nums, dp));

        return dp[i] = maxProfit;
    }
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0); 


        for(int i = n - 2; i >= 0; i--) {

            int maxProfit = 0;

            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[i]) {
                    profit = nums[j] - nums[i];
                }

                maxProfit = max(Profit, profit);
            }

            dp[i] = max(maxProfit, dp[i + 1]);
        }

        return dp[0];
    }
};