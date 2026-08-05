class Solution {
public:
    bool find(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(j == p.size()) {
            return i == s.size();
        }

        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        if(j + 1 < p.size() && p[j + 1] == '*') {
            return find(i, j + 2, s, p, dp) || (match && find(i + 1, j, s, p, dp));
        }

        if(match) return find(i + 1, j + 1, s, p, dp);

        return false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return find(0, 0, s, p, dp);
    }
};