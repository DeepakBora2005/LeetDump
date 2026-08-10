class Solution {
public:
    int find(int i, int j, vector<int> &nums, vector<vector<int>> &dp, vector<int> &p, vector<int> &s) {
        if(i == j) return 0;

        int leftMost = s[i] - find(i + 1, j, nums, dp, p, s);
        int rightMost = p[j] - find(i, j - 1, nums, dp, p, s);

        return max(leftMost, rightMost);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        prefix[0] = stones[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = stones[i] + prefix[i - 1];
        }

        suffix[n - 1] = stones[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = stones[i] + suffix[i + 1];
        }

        return find(0, n - 1, stones, dp, prefix, suffix);
    }
};