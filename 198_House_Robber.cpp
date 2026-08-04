class Solution {
public:
    int find(int index, vector<int> &nums, vector<int> &dp) {
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int first = nums[index] + find(index + 2, nums, dp);
        int second = find(index + 1, nums, dp);

        return dp[index] = max(first, second);
    }

    int rob(vector<int>& nums) {
        int ans = 0;

        vector<int> dp(nums.size(), -1);

        if(nums.size() == 1) return nums[0];

        return find(0, nums, dp);
    }
};