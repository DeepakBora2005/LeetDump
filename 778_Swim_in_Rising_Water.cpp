class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool possible(int row, int col, int n, vector<vector<int>> &grid, int mid, vector<vector<bool>> &visited) {
        if(row >= n || row < 0 || col < 0 || col >= n) return false;

        if(grid[row][col] > mid) return false;

        if(visited[row][col]) return false;

        if(row == n - 1 && col == n - 1) {
            return true;
        }

        visited[row][col] = true;

        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(possible(nr, nc, n, grid, mid, visited)) return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int low = 0;
        int high = (n * n) - 1;

        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if(possible(0, 0, n, grid, mid, visited)) {
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