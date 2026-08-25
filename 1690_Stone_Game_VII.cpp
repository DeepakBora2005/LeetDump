class Solution {
public:
    int find(int i, int j, vector<int> &nums, vector<int> &prefix, vector<vector<int>> &dp) {
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int leftSum = prefix[j] - prefix[i];
        int leftMost = leftSum - find(i + 1, j, nums, prefix, dp);

        int rightSum = prefix[j - 1] - (i > 0 ? prefix[i - 1] : 0);
        int rightMost = rightSum - find(i, j - 1, nums, prefix, dp);

        return dp[i][j] = max(leftMost, rightMost);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = stones[i] + prefix[i - 1];
        }

        return find(0, n - 1, stones, prefix, dp);
    }
};