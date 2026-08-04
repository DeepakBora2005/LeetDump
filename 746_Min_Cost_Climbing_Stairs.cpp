class Solution {
public:
    int find(int index, int n, vector<int> &cost, vector<int> &dp) {
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        return dp[index] = cost[index] + min(find(index + 1, n, cost, dp), find(index + 2, n, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return min(find(0, n, cost, dp1), find(1, n, cost, dp2));
    }
};