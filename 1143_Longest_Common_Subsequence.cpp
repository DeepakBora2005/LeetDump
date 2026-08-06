class Solution {
public:
    int find(int first, int second, string &text1, string &text2, vector<vector<int>> &dp) {
        if(first == text1.size() || second == text2.size()) {
            return 0;
        }

        if(dp[first][second] != -1) return dp[first][second];

        if(text1[first] == text2[second]) {
            return dp[first][second] = 1 + find(first + 1, second + 1, text1, text2, dp);
        }

        return dp[first][second] = max(find(first + 1, second, text1, text2, dp), find(first, second + 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        int i, j;
        for(i = 1; i <= m; i++) {
            for(j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[i - 1][j - 1];
    }
};