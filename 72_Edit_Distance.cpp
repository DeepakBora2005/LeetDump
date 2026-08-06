class Solution {
public:
    int find(int first, int second, string &w1, string &w2, vector<vector<int>> &dp) {
        if(first == w1.size()) {
            return w2.size() - second;
        }

        if(second == w2.size()) {
            return w1.size() - first;
        }

        if(dp[first][second] != -1) return dp[first][second];

        if(w1[first] == w2[second]) {
            return dp[first][second] = find(first + 1, second + 1, w1, w2, dp);
        }

        int insert = 1 + find(first, second + 1, w1, w2, dp);

        int del = 1 + find(first + 1, second, w1, w2, dp);

        int replace = 1 + find(first + 1, second + 1, w1, w2, dp);

        return dp[first][second] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[m][n];
    }
};