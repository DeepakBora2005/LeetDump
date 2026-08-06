class Solution {
public:
    void find(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp, int &ans) {
        int m = nums.size();
        int n = nums[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(nums[i][j] == -1) return;

        if(nums[i][j] == 1) ans++;

        find(i + 1, j, nums, dp, ans);
        
        find(i, j + 1, nums, dp, ans);
    }

    int cherryPickup(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;    

        find(0, 0, nums, dp, ans);

        return ans;
    }
};