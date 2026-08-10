class Solution {
public:
    int find(int i, int j, vector<int> &nums, vector<int> &prefix, vector<vector<int>> &dp) {
        if(i >= j) return 0;

        if(dp[i][j] != 0) return dp[i][j];

        int ans = 0;
        for(int k = i; k < j; k++) {
            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if(leftSum < rightSum) {
                ans = max(ans, leftSum + find(i, k, nums, prefix, dp));
            }
            else if(leftSum > rightSum) {
                ans = max(ans, rightSum + find(k + 1, j, nums, prefix, dp));
            }
            else {
                ans = max(ans, leftSum + max(find(i, k, nums, prefix, dp), find(k + 1, j, nums, prefix ,dp)));
            }
        }   

        return dp[i][j] = ans;     
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = stoneValue[i] + prefix[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, n - 1, stoneValue, prefix, dp);
    }
};