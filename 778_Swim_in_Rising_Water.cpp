class Solution {
public:
    bool possible(int row, int col, int m, int n, vector<vector<int>> &grid, int mid, vector<vector<bool>> &visited) {
        if(row >= m || row < 0 || col < 0 || col >= n) return false;

        if(grid[row][col] > mid) return false;

        if(visited[row][col]) return false;

        if(row == m - 1 && col == n - 1) {
            return true;
        }

        visited[row][col] = true;

        if(possible(row + 1, col, m, n, grid, mid, visited)) {
            return true;
        }

        if(possible(row - 1, col, m, n, grid, mid, visited)) {
            return true;
        }

        if(possible(row, col + 1, m, n, grid, mid, visited)) {
            return true;
        }

        if(possible(row, col - 1, m, n, grid, mid, visited)) {
            return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int low = 0;
        int high = (m * n) - 1;

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            vector<vector<bool>> visited(m, vector<bool>(n, false));

            if(possible(0, 0, m, n, grid, mid, visited)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};