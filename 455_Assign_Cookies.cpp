class Solution {
public:
    int find(int i, int j, vector<int> &g, vector<int> &s, vector<vector<int>> &dp) {
        int m = g.size();
        int n = s.size();

        if(i == m || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(g[i] <= s[j]) {
            take = 1 + find(i + 1, j + 1, g, s, dp);
        }

        int notTake = find(i, j + 1, g, s, dp);

        int ans = max(take, notTake);

        return dp[i][j] = ans;
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