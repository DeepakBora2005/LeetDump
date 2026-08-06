class Solution {
public:
    void find(int i, int j, vector<vector<int>> &nums, vector<vector<bool>> &vis, int &ans) {
        int m = nums.size();
        int n = nums[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(nums[i][j] == -1) return;

        if(nums[i][j] == 1 && !vis[i][j]) ans++;

        if(nums[i][j] == 0 || nums[i][j] == 1) {
            find(i + 1, j, nums, vis, ans);
        
            find(i, j + 1, nums, vis, ans);
        }
    }

    int cherryPickup(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        int ans = 0;    

        find(0, 0, nums, dp, ans);

        return ans;
    }
};