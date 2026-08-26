class Solution {
public:
    int find(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        int n = nums.size();

        if(dp[i][j] != -1) return dp[i][j];

        if(i > j) return 0;

        int ans = 0;
        for(int k = i; k <= j; k++) {
            int cost =  nums[i - 1] * nums[k] * nums[j + 1] + find(i, k - 1, nums, dp) + find(k + 1, j, nums, dp);

            ans = max(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(1, n - 2, nums, dp);
    }
};