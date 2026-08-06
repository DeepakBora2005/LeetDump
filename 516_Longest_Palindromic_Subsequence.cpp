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

        int ans = 0;
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};