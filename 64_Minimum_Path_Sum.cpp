class Solution {
public:
    int find(int row, int col, int m, int n, vector<vector<int>> &nums, vector<vector<int>> &dp) {
        if(row >= m || col >= n) return INT_MAX;

        if(row == m - 1 && col == n - 1) return nums[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int down = find(row + 1, col, m, n, nums, dp);
        int right = find(row, col + 1, m, n, nums, dp);

        return dp[row][col] = nums[row][col] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, m, n, grid, dp);
    }
};