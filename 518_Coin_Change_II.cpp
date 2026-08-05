class Solution {
public: 
    int find(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(amount == 0) return 1;

        if(index == coins.size() || amount < 0) return 0;

        if(dp[index][amount] != -1) return dp[index][amount];

        int include = find(index, amount - coins[index], coins, dp);
        int exclude = find(index + 1, amount, coins, dp);

        return dp[index][amount] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return find(0, amount, coins, dp);
    }
};