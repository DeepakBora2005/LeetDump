class Solution {
public:
    int find(int i, int j, vector<int> &g, vector<int> &s, vector<vector<int>> &dp) {
        int m = g.size();
        int n = s.size();

        if(i == m || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(g[i] <= s[j]) {
            return dp[i][j] = 1 + find(i + 1, j + 1, g, s, dp);
        }

        return dp[i][j] = find(i, j + 1, g, s, dp);
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size();
        int n = s.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, g, s, dp);
    }
};