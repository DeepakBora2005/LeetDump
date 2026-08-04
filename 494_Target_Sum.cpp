class Solution {
public: 
    int find(int row, int col, vector<vector<int>> &tri, vector<vector<int>> &dp) { 
        int m = tri.size();

        if(row == m - 1) return tri[row][col];

        if(dp[row][col] != INT_MAX) return dp[row][col];

        int down = find(row + 1, col, tri, dp);
        int downRight = find(row + 1, col + 1, tri, dp);

        return dp[row][col] = tri[row][col] + min(down, downRight);
    }

    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
    
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));

        return find(0, 0, tri, dp);
    }
};