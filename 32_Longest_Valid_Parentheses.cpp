class Solution {
public:
    int find(int i, int open, string &s, vector<vector<int>> &dp)  {
        int n = s.size();

        if(i >= n) return 0;

        if(dp[i][open] != -1) return dp[i][open];

        int skip = find(i + 1, open, s, dp);
        int take = 0;

        if(open == 0) {
            if(s[i] == '(') {
                take = 1 + find(i + 1, 1, s, dp);
            }
        }
        else {
            if(s[i] == ')') {
                take = 1 + find(i + 1, 0, s, dp);
            }
        }

        return dp[i][open] = max(skip, take);
    }   

    int longestValidParentheses(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return find(0, 0, s, dp);
    }
};