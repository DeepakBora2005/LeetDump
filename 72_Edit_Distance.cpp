class Solution {
public:
    int find(int first, int second, string &s1, string &s2, vector<vector<int>> &dp) {
        if(first == s1.size() || second == s2.size()) {
            return 0;
        }

        if(dp[first][second] != -1) {
            return dp[first][second];
        }

        if(s1[first] == s2[second]) {
            return dp[first][second] = 1 + find(first + 1, second + 1, s1, s2, dp);
        }

        return dp[first][second] = max(find(first + 1, second, s1, s2, dp), find(first, second + 1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int n = s1.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, 0, s1, s2, dp);
    }
};