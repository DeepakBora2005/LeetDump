class Solution {
public:
    int find(int index, int M, vector<int> &piles, vector<int> &suffix, vector<vector<int>> &dp) {
        int n = piles.size();

        if(index >= n) return 0;

        if(2 * M >= n - index) return suffix[index];

        int ans = 0;

        for(int X = 1; X <= 2 * M; X++) {
            int current = suffix[index] - find(index + X, max(M, X), piles, suffix, dp);

            ans = max(ans, current);
        }

        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return find(0, 1, piles, suffix, dp);
    }
};