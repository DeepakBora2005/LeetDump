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

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }

            prev = curr;
        }

        return curr[n];
    }
};