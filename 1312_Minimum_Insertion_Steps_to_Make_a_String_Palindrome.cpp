class Solution {
public:
    int find(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if(i == s.size() || j == t.size()) return 0;

        if(s[i] == t[j]) {
            return 1 + find(i + 1, j + 1, s, t, dp);
        }

        return max(find(i + 1, j, s, t, dp), find(i, j + 1, s, t, dp));
    }

    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int x = find(0, 0, s, t, dp);

        return n - x;
    }
};