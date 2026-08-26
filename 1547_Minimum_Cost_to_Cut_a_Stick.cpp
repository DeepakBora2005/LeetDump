class Solution {
public:
    int find(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int index = i; index <= j; index++) {
            int cost = cuts[j + 1] - cuts[i - 1] + find(i, index - 1, cuts, dp) + find(index + 1, j, cuts, dp);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, 0));

        for(int i = c - 2; i >= 1; i--) {
            for(int j = i; j <= c - 2; j++) {
    
                for(int k = i; k <= j; k++) {
                    dp[i][j] = INT_MAX;

                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][c - 2];
    }
};