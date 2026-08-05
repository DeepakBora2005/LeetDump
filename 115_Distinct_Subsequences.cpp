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

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, s, t, dp);
    }
};