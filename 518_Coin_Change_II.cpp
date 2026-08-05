class Solution {
public:
    int find(int index, int n, vector<int> &coins, int target, vector<vector<int>> &dp) {
        if(target == 0) return 0;

        if(index == n || target < 0) return 1e9;
 
        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        int include = find(index, n, coins, target - coins[index], dp);

        if(include != 1e9) {
            include = 1 + include;
        }

        int exclude = find(index + 1, n, coins, target, dp);

        return dp[index][target] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
 
        int ans = find(0, n, coins, amount, dp);

        if(ans >= 1e9) {
            return -1;
        }

        return ans;
    }
};