class Solution {
public:
    int find(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        int k = i + j;

        if(i == s1.size() && j == s2.size()) {
            if(k == s3.size()) return 1;
            else return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i < s1.size() && s1[i] == s3[k] && find(i + 1, j, s1, s2, s3, dp)) {
            return dp[i][j] = 1;
        }
        
        if(j < s2.size() && s2[j] == s3[k] && find(i, j + 1, s1, s2, s3, dp)) {
            return dp[i][j] = 1;
        }

        return dp[i][j] = 0;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return find(0, 0, s1, s2, s3, dp);
    }
};