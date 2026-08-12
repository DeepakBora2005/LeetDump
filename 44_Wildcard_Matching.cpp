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

        return false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, s, p, dp);
    }
};