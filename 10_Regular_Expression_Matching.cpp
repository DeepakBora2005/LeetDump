class Solution {
public:
    bool find(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i == s.size() && j == p.size()) return true;

        if(j == p.size()) return false;

        if(i == s.size()) {
            for(int k = j; k < p.size(); k++) {
                if(p[k] != '*') return false;
            }

            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = find(i + 1, j + 1, s, p, dp);

        if(p[j] == '*') {
            return dp[i][j] = find(i + 1, j, s, p, dp) || find(i, j + 1, s, p, dp);
        }

        return dp[i][j] = false;
    } 
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return find(0, 0, s, p, dp);
    }
};