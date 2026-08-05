class Solution {
public:
    bool find(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i == s.size() && j == p.size()) return true;

        if(j == p.size()) return false;

        if(i == s.size()) {
            while(j < p.size()) {
                if(p[j] != '*') {
                    return false;
                }
                
                j++;
            }

            return true;
        }

        if(s[i] == p[j] || p[j] == '?') return find(i + 1, j + 1, s, p, dp);

        if(p[j] == '*') {
            return find(i + 1, j, s, p, dp) || find(i, j + 1, s, p, dp);
        }

        return false;
    } 
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, s, p, dp);
    }
};