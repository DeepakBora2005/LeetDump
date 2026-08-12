class Solution {
public:
    bool find(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        int m = s.size();
        int n = p.size();

        if(i == m) {
            for(int k = j; k < n; k++) {
                if(p[k] != '*') return 0;
            }

            return 1;
        } 

        if(j == n) {
            if(i == m) return 1;    
            else return 0;
        }

        if(s[i] == p[j]) {
            return find(i + 1, j + 1, s, p, dp);
        }

        return find(i + 1, j, s, p, dp) || find(i, j + 1, s, p, dp);
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, s, p, dp);
    }
};