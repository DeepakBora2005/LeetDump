class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int find(int i, int j, vector<vector<int>> &nums) {
        int m = nums.size();
        int n = nums[0].size();

        int ans = 1;
     
        for(int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && nums[nr][nc] > nums[i][j]) {
                ans = max(ans, 1 + find(nr, nc, nums));
            }    
        }

        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& nums) {
        int ans = 1;

        int m = nums.size();
        int n = nums[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, find(i, j, nums));
            }
        }

        return ans;
    }
};