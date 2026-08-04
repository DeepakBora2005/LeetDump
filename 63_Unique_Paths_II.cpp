class Solution {
public:
    int find(int row, int col, int m, int n, vector<vector<int>> &nums, vector<vector<int>> &dp) {
        if(row >= m || col >= n) return 0;

        if(nums[row][col] == 1) return 0;
        
        if(row == m - 1 && col == n - 1) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = find(row + 1, col, m, n, nums, dp) + find(row, col + 1, m, n, nums, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return find(0, 0, m, n, nums, dp);
    }
};