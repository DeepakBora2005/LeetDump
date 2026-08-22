class Solution {
public:
    bool find(int i, string &s, int open, vector<vector<int>> &dp) {
        if(open < 0) return false;

        if(i == s.length()) return open == 0;

        if(dp[i][open] != -1) return dp[i][open];

        if(s[i] == '(') {
            return dp[i][open] = find(i + 1, s, open + 1, dp);
        }
        else if(s[i] == ')') {
            return dp[i][open] = find(i + 1, s, open - 1, dp);
        }
        else {
            return dp[i][open] = find(i + 1, s, open + 1, dp) || find(i + 1, s, open - 1, dp) || find(i + 1, s, open, dp);
        }
    }

    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return find(0, s, 0, dp);
    }
};