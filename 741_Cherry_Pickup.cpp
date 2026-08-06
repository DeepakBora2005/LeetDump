class Solution {
public:
    void find(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &vis, int &ans) {
        int m = nums.size();
        int n = nums[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(nums[i][j] == -1) {
            vis[i][j] = -1;
            return;
        }

        if(nums[i][j] == 1) vis[i][j] = 1;

        vis[i][j] = 2;

        if(nums[i][j] == 0 || nums[i][j] == 1) {
            find(i + 1, j, nums, vis, ans);
        
            find(i, j + 1, nums, vis, ans);
        }
    }

    int cherryPickup(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int ans = 0;    

        find(0, 0, nums, vis, ans);

        if(vis[m - 1][n - 1] != 2) return 0;

        return ans;
    }
};