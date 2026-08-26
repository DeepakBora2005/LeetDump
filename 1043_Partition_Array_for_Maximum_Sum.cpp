class Solution {
public: 
    int find(int i, int k, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int maxi = INT_MIN;
        int len = 0;
        int ans = 0;

        for(int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, nums[j]);
            int sum = (len * maxi) + find(j + 1, k, nums, dp);

            ans = max(ans, sum);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            int len = 0;
            int maxi = INT_MIN;
            int ans = 0;

            for(int j = i; j < min(n, i + k); j++) {
                len++;
                maxi = max(maxi, nums[j]);
                int sum = (len * maxi) + dp[j + 1];

                ans = max(ans, sum);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};