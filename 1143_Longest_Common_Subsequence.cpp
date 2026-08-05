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

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, text1, text2, dp);
    }
};