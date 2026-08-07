class Solution {
public:
    int find(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(j == t.size()) return 1;

        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = find(i + 1, j + 1, s, t, dp) + find(i + 1, j, s, t, dp);
        }
        else {
            return dp[i][j] = find(i + 1, j, s, t, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};