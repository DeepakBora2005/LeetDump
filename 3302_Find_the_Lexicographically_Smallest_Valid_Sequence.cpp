class Solution {
public:
    bool find(int i, int j, int changed, string &s, string &t, vector<int> &ans, vector<vector<vector<int>>> &dp) {
        int m = s.size();
        int n = t.size();

        if(j == n) {
            return true;
        }

        if(i == m) {
            return false;
        }

        if(dp[i][j][changed] != -1) {
            dp[i][j][changed];
        } 

        if(s[i] == t[j]) {
            ans.push_back(i);
            if(find(i + 1, j + 1, changed, s, t, ans, dp)) {
                return true;
            }
            ans.pop_back();
        }
        else if(changed == 0) {
            ans.push_back(i);
            if(find(i + 1, j + 1, 1, s, t, ans, dp)) {
                return true;
            }
            ans.pop_back();
        }

        if(find(i + 1, j, changed, s, t, ans, dp)) {
            return true;
        }

        return dp[i][j][changed] = false;
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));

        find(0, 0, 0, word1, word2, ans, dp);

        return ans;
    }
};