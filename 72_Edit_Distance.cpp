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

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, word1, word2, dp);
    }
};