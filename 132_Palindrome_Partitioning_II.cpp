class Solution {
public:
    int find(int i, string &s, vector<int> &dp) {    
        int n = s.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j = i; j < n; j++) {
            if(isValid(s, i, j)) {
                int cost = 1 + find(j + 1, s, dp);

                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    } 

    bool isValid(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int minCut(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);

        return find(0, s, dp) - 1;
    }
};