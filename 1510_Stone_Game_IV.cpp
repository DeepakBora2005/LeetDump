class Solution {
public:
    bool find(int n, vector<bool> &dp) {
        if(n == 0) return false;

        for(int i = 1; i * i <= n; i++) {
            if(find(n - (i * i), dp) == false) return true; 
        }

        return false;
    }

    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        return find(n, dp);
    }
};