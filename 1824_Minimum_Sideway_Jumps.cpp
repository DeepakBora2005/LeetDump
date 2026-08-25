class Solution {
public:
    int find(int index, int lane, vector<int> &nums, vector<vector<int>> &dp) {
        int n = nums.size();

        if(index >= n - 1) {
            return 0;
        }

        if(dp[index][lane] != -1) return dp[index][lane];

        if(nums[index + 1] != lane) {
            return dp[index][lane] = find(index + 1, lane, nums, dp);
        }

        int ans = INT_MAX;

        if(lane != 1 && nums[index] != 1) {
            ans = min(ans, 1 + find(index, 1, nums, dp));
        }
        if(lane != 2 && nums[index] != 2) {
            ans = min(ans, 1 + find(index, 2, nums, dp));
        }
        if(lane != 3 && nums[index] != 3) {
            ans = min(ans, 1 + find(index, 3, nums, dp));
        }

        return dp[index][lane] = ans;
    }

    int minSideJumps(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return find(0, 2, nums, dp);
    }
};