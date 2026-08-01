class Solution {
public:
    int find(vector<int> &piles, int start, int end, vector<vector<int>> &dp) {
        if(start == end) {
            return piles[start];
        }

        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int leftMost = piles[start] - find(piles, start + 1, end, dp);
        int rightMost = piles[end] - find(piles, start, end - 1, dp);

        return dp[start][end] = max(leftMost, rightMost);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(piles, 0, n - 1, dp) > 0;
    }
};